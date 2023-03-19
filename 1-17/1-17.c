#include <stdio.h>
#define MAXLINE 1000
#define MIN_LINE_LENGTH 5

/* Print all input lines that are longer than 5 characters */

int getlinelength(char line[], int limit);

main() {
	int linelength;
	char line[MAXLINE];

	while ((linelength = getlinelength(line, MAXLINE)) > 0)
	{
		if (linelength > MIN_LINE_LENGTH)
			printf("%s", line);
	}

}

int getlinelength(char line[], int limit)
{
	int c, i;

	for (i = 0; i < limit - 2 && (c = getchar()) != EOF && c != '\n'; i++)
		line[i] = c;
	if (c == '\n') {
		line[i] = c;
		i++;
	}

	line[i] = '\0';
	return i;

}