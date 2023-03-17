#include <stdio.h>

/* Replace tabs and backslashes with visable characters */

main() {
	int c;

	while ((c = getchar()) != EOF) {
		if (c == '\t')
			printf("\\t");
		else if (c == '\\')
			printf("\\\\");
		else
			putchar(c);
	}
}