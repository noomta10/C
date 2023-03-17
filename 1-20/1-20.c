#include <stdio.h>
#define TAB 8	

/* Replace tabs and to spaces */

main() {
	int c;
	int position = 1;
	int blanksNumber = 0;

	while ((c = getchar()) != EOF)
	{
		if (c == '\t') {
			blanksNumber = TAB - (position - 1) % TAB;
			while (blanksNumber > 0)
			{
				putchar(' ');
				position++;
				blanksNumber--;
			}
		}
		else if (c == '\n') {
			putchar(c);
			position = 1;
		}
		else {
			putchar(c);
			position++;
		}

	}
}