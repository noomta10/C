/* chapter 5, fourth example.
Example - print array */
#include <stdio.h>

void func(int* p) {
	printf("%d\n", *p);
	return;
}

main() {
	int a[10];
	int* pa;
	a[0] = 8;
	pa = &a[0];
	func(a);
	func(pa);
}