/* The function should receive the following floating-point value from the input, 
and put it into the *fp pointer. */

#include <stdio.h>
#include <ctype.h>
#define BUFSIZE 100

static char buf[BUFSIZE]; /* buffer for ungetch */
static int bufp = 0; /* next free position in buf */

int my_getch(void) /* get a (possibly pushed back) character */
{
	return (bufp > 0 ? buf[--bufp] : getchar());
}

void my_ungetch(int c) /* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}


/* get next float from input into *fp */
float get_float(float* fp)
{
	int c, sign;
	long exp = 10;

	/* skip white spaces */
	while (isspace(c = my_getch()))
		;

	/* Not a valid beginning of floating point number */
	if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
		my_ungetch(c);
		return 0.0;
	}

	/* decide whether there is a sign */
	sign = (c == '-') ? -1 : 1;
	if (c == '-' || c == '+')
		c = my_getch();

	/* calculate part before the decimal point */
	for (*fp = 0.0; isdigit(c); c = my_getch())
		*fp = 10 * *fp + (c - '0');

	/* calculate part after the decimal point */
	if (c == '.') {
		for (c = my_getch(); isdigit(c); c = my_getch(), exp *= 10)
			*fp = *fp + (float)(c - '0') / exp;
	}

	*fp *= sign;

	if (c != EOF)
		my_ungetch(c);
	return c;
}

main() {
	float ret_val;
	get_float(&ret_val);
	printf("%g\n", ret_val);
}

