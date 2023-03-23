#include <stdio.h>

/* Count 1 bits  */

int count_bits(unsigned int number);

int main() {
	printf("Number of 1 bits: %d", count_bits(4));
	
	return 0;
}

int count_bits(unsigned int number){
	int bits_number;

	for (bits_number = 0; number != 0; number &= (number - 1))
		bits_number++;
	
	return bits_number;
}
