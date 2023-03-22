/* Count_bits is a function that sums up and returns the number of bits that are on, on the even places,
in an unsigned long variable. The function gets the number and use bitwise operators 
in order to find out how many bits on the even places are on.
Main function asks for an input from the user, prints it, sends it to count_bits function,
and finally, prints the return value. */

#define _CRT_SECURE_NO_WARNINGS
#define OK 0
#define STEP 2
#include <stdio.h>

int reset_bit_index(unsigned long number);

int main() {
	unsigned long number;
	printf("Enter a number: ");
	scanf("%lu", &number);
	printf("Number is: %lu\n", number);
	printf("number of bits that are ON on the even places: %d\n", reset_bit_index(number));
	return OK;
}

/* Count_bits is a function that sums up and returns the number of bits that are on, on the even places,
in an unsigned long variable.
The function gets an unsigned long number and use bitwise operators AND and RIGHT SHIFT (until the number becomes zero).
It returns the number of bits on the even places are on.
We assume that the number the function recives is not larger than max value of unsigned long (4294967295) */
int reset_bit_index(unsigned long number) {
	int bit_count;
	bit_count = 0;

	while (number) {
		if (number & 1)
			bit_count++;

		number = number >> STEP;
	}

	return bit_count;
}