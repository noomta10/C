#include <stdio.h>

/* Returns the The value of x integer, after rotation to the right of n places */

int rightrot(unsigned int x, int n);
int find_int_length(void);

int main() {
	int number = 49U;
	int rotation = 2;
	printf("Number after right rotation of %d places- %d", rotation, rightrot(number, rotation));
}

/* Find int length (usually 32 bits) */
find_int_length(void) {
	unsigned int int_length = ~0;
	int bit_count;
	for (bit_count = 0; int_length > 0; bit_count++) {
		int_length = int_length >> 1;
	}

	return bit_count;
}

int rightrot(unsigned int x, int n) {
	return ((x << (find_int_length() - n)) | (x >> n));
}