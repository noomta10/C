#include <stdio.h>
#define MAXLINE 1000

/* Remove trailing blanks and tabs and delete blank lines */

int getlinelength(char line[], int limit);
int reverse(char line[], char reversedline[]);

main8() {
	char line[MAXLINE];
	char reversedline[MAXLINE];

	while (getlinelength(line, MAXLINE) > 0) {
		reverse(line, reversedline);
		printf("%s", reversedline);
	}

	return 0;
}

int reverse(char line[], char reversedline[]) {
	int i = 0;
	int j = 0;
	
	while (line[i] != '\0')
		i++;
	
	i--;

	while (i >= 0)
	{
		reversedline[j++] = line[i--];
	}

	reversedline[j] = '\0';
	return j;
}
