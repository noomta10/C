#include <stdio.h>

/* Prints the number of digits, blanks and other characters */

demo1() {
	int c;
	int numberOfWhites = 0;
	int numberOfOthers = 0;
	int numberOfDigits[10];

	for (int i = 0; i < 10; i++)
		numberOfDigits[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c >= '0' && c <= '9')
			numberOfDigits[c - '0']++;
		else if (c == ' ' || c == '\n' || c == '\t')
			numberOfWhites++;
		else
			numberOfOthers++;
	}

	printf("Digits: ");
	for (int i = 0; i < 10; i++)
		printf("%d: %d, ", i, numberOfDigits[i]);
	printf("Whites: %d, Others: %d", numberOfWhites, numberOfOthers);

}