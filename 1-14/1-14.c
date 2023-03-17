#include <stdio.h>
#define IN 1
#define OUT 0
#define MAX_DIFFERENT_CHARS 128

/* Creates a histogram of the frequencies of different characters */

main() {
	int c;
	int cCounter[MAX_DIFFERENT_CHARS];

	for (int i = 0; i < MAX_DIFFERENT_CHARS; i++)
		cCounter[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c < MAX_DIFFERENT_CHARS)
			cCounter[c]++;
	}

	for (int i = 0; i < MAX_DIFFERENT_CHARS; i++) {
		if (isprint(i))
			printf("%5d - %c - %5d\n", i, i, cCounter[i]);
		else
			printf("%5d -   - %5d\n", i, cCounter[i]);
	}


}