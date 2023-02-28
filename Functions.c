#include <stdio.h>

/* Tests pow function */

demo2() {
	printf("Powers of 2 up to 10:\n");

	for (int i = 0; i < 10; i++) {
		printf("%3d %3d\n", i, pow(2, i));
	}

}


/* Raise base to n-th power (n >= 0) */

int pow(int base, int n) {
	int power = 1;
	
	for (int i = 1; i <= n; i++)
		power = power * base;
	
	return power;

}