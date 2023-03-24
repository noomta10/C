#include <stdio.h>
#include <string.h>

/* Turns off (sets to zero) bit in specified index  */

int count_bits(unsigned int number, int index);

int main() {
	int number = 15;
	int index = 2;
	printf("Number after turn of bit number %d: %d", index, count_bits(number, index));
}

int count_bits(unsigned int number, int index) {
	int mask = ~(1 << index);
	return mask & number;
}

