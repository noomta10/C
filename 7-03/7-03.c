#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdarg.h>

/* compute sum using variable-length argument list */
void sum(char*, int, ...);

int main(void) {
	sum("The sum of 1+2+3 is %d.\n", 4, 1, 2, 3, 4);
	return 0;
}

void sum(char* string, int num_args, ...) {
	int sum = 0;
	va_list ap;
	int i;
	va_start(ap, num_args);
	for (i = 0; i < num_args; i++)
		sum += va_arg(ap, int);
	printf(string, sum);
	va_end(ap);
}

