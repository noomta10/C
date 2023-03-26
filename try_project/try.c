#include <stdio.h>

main(void) {
	int y;
	int x = 2;

	int* pointer_to_x = &x;

	y = *pointer_to_x + 1;

	printf("%d\n", y);
	printf("%d\n", *pointer_to_x);
}
