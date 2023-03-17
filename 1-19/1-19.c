#include <stdio.h>
#define MAXLINE 1000

/* Reverse a string */

int getlinelength(char line[], int limit);
void reverse(char line[]);


main() {
	char line[MAXLINE];

	while (getlinelength(line, MAXLINE) > 0) {
		reverse(line);
		printf("%s", line);
	}

	return 0;
}




void reverse(char line[])
{
	int i = 0;
	int j = 0;
	char temp;

	while (line[i] != '\0')
		i++;

	i--;

	if (j < i)
		i--;

	while (i >= j)
	{
		temp = line[j];
		line[j] = line[i];
		line[i] = temp;
		i--;
		j++;
	}
}
