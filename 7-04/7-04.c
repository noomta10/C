#include <stdio.h>
#include <stdarg.h>

/* miniscanf: minimal scanf with variable argument list */
void mini_scanf(char* fmt, ...) {
	va_list ap;
	char* p;
	int* iptr;
	float* fptr;
	va_start(ap, fmt);
	for (p = fmt; *p != '\0'; p++)
	{
		if (*p != '%')
			continue;
		switch (*++p)
		{
		case 'd':
			iptr = va_arg(ap, int*);
			scanf("%d", iptr);
			break;
		case 'f':
			fptr = va_arg(ap, float*);
			scanf("%f", fptr);
			break;
		default:
			printf("mini_scanf: unknown format %c\n", *p);
			break;
		}
	}
	va_end(ap);
}


main() {
	int i;
	float f;
	mini_scanf("%f %d", &f, &i);
		printf("%f %d\n", f, i);
}