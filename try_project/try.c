/* program cat – concatenate files using UNIX system access */
/* Test if input is capable of seeking */

#include <stdio.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>

int seek_test(int fd)
{
	if (lseek(fd, 0, 0) == -1)
		printf("cannot seek\n");
	else
		printf("seek is OK\n");
	return(0);
}