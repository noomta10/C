#include <stdio.h>
#include <string.h>

/* Turn off (set to zero) bit in specified index  */

int reset_bit_index(unsigned int number, int index);

int main() {
	int number = 15;
	int index = 2;
	printf("Number after turn of bit number %d: %d", index, reset_bit_index(number, index));
}

int reset_bit_index(unsigned int number, int index) {
	int mask = ~(1 << index);
	return mask & number;
}

