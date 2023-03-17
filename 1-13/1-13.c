#include <stdio.h>
#define MAX_WORD_LENGTH 10
#define IN 1
#define OUT 0

/* Creates a histogram of the lengths of words */

main() {
	int c;
	int cCount = 0;
	int overflowCount = 0;
	int state = OUT;
	int wordLengthCounter[MAX_WORD_LENGTH];

	for (int i = 0; i < MAX_WORD_LENGTH; i++)
		wordLengthCounter[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
			if (cCount > MAX_WORD_LENGTH)
				overflowCount++;
			if (cCount > 0)
				wordLengthCounter[cCount - 1]++;
			cCount = 0;
		}
		else if (state == OUT) {
			state = IN;
			cCount = 1;
		}
		else
			cCount++;
	}

	for (int i = 0; i < MAX_WORD_LENGTH; i++) {
		printf("%d: %d\n", i + 1, wordLengthCounter[i]);
	}

	if (overflowCount > 0)
		printf("Overflow count: %d", overflowCount);

}