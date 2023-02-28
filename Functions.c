#include <stdio.h>

/* Tests pow function */

demo2() {

	printf("Power is: %d", pow(2, 4));

}


/* Raise base to n-th power (n >= 0) */

int pow(int base, int n) {
	int power = 1;
	
	for (int i = 1; i <= n; i++)
		power = power * base;
	
	return power;

}