/* tail -n: print the last n lines
the default of n is 10 if it hasn't been specified from the command line. It is
assumed that lines can be no longer than 100 characters. If the number of
input lines is less than n then print all of them.
method:
a. Get the value of n from the command line
b. Allocate n pointers to char *; these pointers will hold the pointers to the n
lines. They will be handled as a sort of list. The variable head will always
point to the first char * in the list.
c. Let number-of-lines = 0;
d. Read next line.
e. If list isn't full (number-of-lines read is less then n) then allocate a new
line. Copy to it the line which has been read and put this line in the list.
 Otherwise, switch the oldest line (the one which is pointed to by head) with the
new line, and advance head to the next line.
f. When there are no more lines to be read do the printing.
if number-of-lines read is less than n, print the first number-of-lines in the list
 Otherwise, print the lines from head to n and then the lines from 0 to head - 1. */
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#define MAX_LINE_LEN 100 
#define DEFAULT_N 5 

/* getline: get line into s, return length */
int getline(char s[], int lim) {
	int c;
	int i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
		s[i++] = c;
		if (c == '\n')
			s[i++] = c;
	}
	s[i] = '\0';
	return i;
}

main(int argc, char* argv[]) {
	int number_of_lines = 0; /* The number of lines that has been read */
	char** keep; /* will hold the first address of the list returned by malloc */
	char** head; /* will hold a pointer to the oldest line that has been read */
	char** tmp; /* for indexing through the list while printing */
	char line[MAX_LINE_LEN];
	int tail = DEFAULT_N;

	/* This will allocate a block of tail char * */
	if (argc > 1 && argv[1][0] == '-')
		tail = atof(&argv[1][1]);
	
	head = keep = malloc(tail * sizeof(char*));
	if (head == NULL) {
		printf("malloc failed\n");
		exit(1);
	}

	while (getline(line, MAX_LINE_LEN) > 0) {
		/* less than tail lines have been allocated */
		if (number_of_lines < tail) {
			*head = malloc(MAX_LINE_LEN);
			if (*head == NULL) {
				printf("malloc failed\n");
				exit(1);
			}
		}
		number_of_lines++;
		strcpy(*head, line);
		head++;
		/* back to the beginning of list */
		if (head - keep == tail)
			head = keep;
	}

	/* Printing from head (which always points to the oldest line) to the end of the list */
	if (number_of_lines >= tail) {
		for (tmp = head; tmp - keep < tail; tmp++)
			printf("%s ", *tmp);
	}

	/* Printing the rest. After we printed head[9] (default case) We start printing from the beginning till one entry before head */
		for (tmp = keep; tmp != head; tmp++)
			printf("%s ", *tmp);
}