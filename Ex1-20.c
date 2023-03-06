#include <stdio.h>
#define TAB 4

/* Replace tabs and to spaces */

main9() {
	int c;

	while ((c = getchar()) != EOF)
	{
		if (c == '\t'){
			for(int i = 0; i < TAB; i++)
				putchar(' ');
		}
		else
			putchar(c);
	}
}
