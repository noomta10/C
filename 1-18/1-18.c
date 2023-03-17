#include <stdio.h>
#define MAXLINE 1000

int getlinelength(char line[], int limit);
int removeblanks(char line[]);


/* Remove trailing blanks and tabs and delete blank lines */
main() {
	char line[MAXLINE];

	while (getlinelength(line, MAXLINE) > 0) {
		if (removeblanks(line) > 0)
			printf("%s", line);
	}

	return 0;
}

int removeblanks(char line[]) {
	int i = 0;

	while (line[i] != '\n')
		i++;
	i--; /* Gets the character before '\n' */

	while (i >= 0 && (line[i] == '\t' || line[i] == ' '))
		i--;

	/* i now is the last character */
	if (i >= 0) {
		i++;
		line[i] = '\n';
		i++;
		line[i] = '\0';
	}

	return i;
}

