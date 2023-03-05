#include <stdio.h>
#define MAXLINE 1000

/* Remove trailing blanks and tabs and delete blank lines */

int getlinelength(char line[], int limit);
void reverse(char line[]);


main8() {
	char line[MAXLINE];

	while (getlinelength(line, MAXLINE) > 0) {
		reverse(line);
		printf("%s", line);
	}

	return 0;
}

void reverse(char line[]) {
	int i = 0;
	int j = 0;
	char template;
	
	while (line[i] != '\0')
		i++;
	
	i--;

	if (j < i)
		i--;

	while (i >= 0)
	{
		template = line[j];
		line[j] = line[i];
		line[i] = template;
		i--;
		j++;

	}
}
