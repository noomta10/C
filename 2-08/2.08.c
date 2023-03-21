#include <stdio.h>

/* Returns the The value of x integer, after rotation to the right of n places */

int rightrot(int x, int n);

int main() {
	printf("%d", rightrot(10, 2));
}

int rightrot(int x, int n) {
	return x >> n;
}