#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

#define MAXLINES 5000 /* max number of lines */
#define MAXLEN 1000 /* max length of an input line */

char* lineptr[MAXLINES];
char lines[MAXLINES][MAXLEN];

/* getline (page 29): read a line into s, return length */
int getline(char s[], int lim)
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if (c == '\n') {
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}
/* readlines (page 109): read input lines */
int readlines(char* lineptr[], int maxlines)
{
	int len, nlines;
	char* p, line[MAXLEN];
	nlines = 0;
	while ((len = getline(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = malloc(len)) == NULL)
			return -1;

		else {
			line[len - 1] = '\0'; /* delete newline */
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}
/* readlines2 (new function): read input lines */
/* store lines in array "lines" */
int readlines2(char lines[][MAXLEN], int maxlines)
{
	int len, nlines;
	nlines = 0;
	while ((len = getline(lines[nlines], MAXLEN)) > 0)
		if (nlines >= maxlines)
			return -1;
		else
			lines[nlines++][len - 1] = '\0'; /* delete newline */
	return nlines;
}

int main(int argc, char* argv[])
{
	/* read into cache */
	readlines2(lines, MAXLINES);
	if (argc > 1 && *argv[1] == '2')
	{
		puts("readlines2()");
		readlines2(lines, MAXLINES);
	}
	else
	{
		puts("readlines()");
		readlines(lineptr, MAXLINES);
	}

	return 0;
}