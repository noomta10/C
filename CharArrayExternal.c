#include <stdio.h>
#define MAXLINE 1000

/* Print the longest input line and its length */

int maxlength;
char line[MAXLINE];
char longestline[MAXLINE];

int getlinelengthex(void);
void copyex(void);

demo4() {
	int length;
	extern int maxlength;
	extern char longestline[];

	maxlength = 0;

	while ((length = getlinelengthex()) > 0)
	{
		if (length > maxlength) {
			maxlength = length;
			copyex();
		}

		if (maxlength > 0) 
			printf("%s", longestline);
		
		return 0;
	}
}

int getlinelengthex(void)
{
	int c, i;
	extern char line[];

	for (i = 0; i < MAXLINE - 2 && (c = getchar()) != EOF && c != '\n'; i++)
		line[i] = c;

	if (c == '\n') {
		line[i] = c;
		i++;
	}

	line[i] = '\0';
	return i;
}

void copyex(void)
{
	int i = 0;
	extern char line[], longestline[];

	while ((longestline[i] = line[i]) != '\0')
		i++;
}


