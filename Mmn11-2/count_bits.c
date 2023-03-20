/* Count_bits is a function that sums up and returns the number of bits that are on, on the even places,
in an unsigned long variable. The function gets the number and use bitwise operators 
in order to find out how many bits on the even places are on.
Main function asks for an input from the user, prints it, sends it to count_bits function,
and finally, prints the return value. */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int count_bits(unsigned long number);

int main() {
	unsigned long number;
	printf("Enter a number: ");
	scanf("%lu", &number);
	printf("Number is: %lu\n", number);
	printf("number of bits that are ON on the even places: %d\n", count_bits(number));
	return 0;
}

/* Count_bits is a function that sums up and returns the number of bits that are on, on the even places,
in an unsigned long variable.
The function gets an unsigned long number and use bitwise operators AND and RIGHT SHIFT (until the nunmber becomes zero),
and returns the number of bits on the even places are on. */
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