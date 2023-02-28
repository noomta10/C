#include <stdio.h>
#define MAXLINE 1000

int getlinelength(char line[], int limit);

demo3() {
	int length;
	int maxlength;
	char line[MAXLINE];
	char longest[MAXLINE];
	
	maxlength = 0;
	
	while ((length = getlinelength(line, MAXLINE)) > 0) {
		if (length > maxlength)
			maxlength = length;
	}
	printf("Max line length: %d", maxlength);
}

int getlinelength(char line[], int limit)
{
	int c, i;

	for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		line[i] = c;
	if (c == '\n') {
		line[i] = c;
		i++;
	}

	line[i] = '\0';
	return i;

}
