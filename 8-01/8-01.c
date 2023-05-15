/* program cat – concatenate files using UNIX system access */
#include <stdio.h> 
#include <fcntl.h> 
#define BUFSIZE 1024 

void filecopy(int, int);

int main(int argc, char* argv[]) {
	int fd;

	if (argc == 1)
		filecopy(0, 1);
	else {
		while (--argc > 0)
			if ((fd = open(*++argv, O_RDONLY, 0)) == -1) {
				printf("unix cat: can't open %s\n", *argv);
				return 1;
			}
			else {
				filecopy(fd, 1);
				close(fd);
			}
	}
	return 0;
}
/* filecopy: copy file "in" to file "out" */
void filecopy(int in, int out) {
	int n;
	char buf[BUFSIZE];

	while ((n = read(in, buf, BUFSIZE)) > 0)
		write(out, buf, n);
}