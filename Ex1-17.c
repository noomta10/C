#include <stdio.h>
#define MAXLINE 1000
#define MIN_LINE_LENGTH 5

/* Print all input lines that are longer than 80 characters */

int getlinelength(char line[], int limit);

main6() {
	int linelength;
	char line[MAXLINE];
	
	while ((linelength = getlinelength(line, MAXLINE)) > 0)
	{
		if (linelength > MIN_LINE_LENGTH)
			printf("%s", line);
	}

}