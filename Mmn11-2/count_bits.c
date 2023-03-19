#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int count_bits(unsigned long number);

int main() {
	unsigned long number;
	printf("Enter a number: ");
	scanf("%lu", &number);
	printf("Number is: %lu\n", number);
	printf("number of ON bits in the even places: %d\n", count_bits(number));
	return 0;
}

int count_bits(unsigned long number) {
	int bit_count;
	bit_count = 0;

	while (number) {
		if (number & 1)
			bit_count++;

		number = number >> 2;
	}

	return bit_count;
}