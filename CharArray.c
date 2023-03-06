#include <stdio.h>
#define MAXLINE 1000

/* Print the longest input line and its length */

int getlinelength(char line[], int limit);
void copy(char line[], char longestline[]);

demo3() {
	int length;
	int maxlength;
	char line[MAXLINE];
	char longestline[MAXLINE];
	
	maxlength = 0;
	
	while ((length = getlinelength(line, MAXLINE)) > 0) {
		if (length > maxlength){
			maxlength = length;
			copy(line, longestline);
		}
	}
	printf("Max line length: %d\n", maxlength);
	printf("Line: %s", longestline);
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


/* Copy line array to longestline array*/
void copy(char line[], char longestline[]) {
	int i = 0;

	while ((longestline[i] = line[i]) != '\0') {
		i++;
	}
}


