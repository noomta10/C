/* Reverse polish alculator */

#include <stdio.h>
#include <math.h>
#include <stdlib.h> // for atof- converts string to double

#define MAXOP 100 // max size of oparand or operator
#define NUMBER 0 // signal that a number was found

int getop(char[]);
void push(double);
double pop(void);

int main() {
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("Error: zero division");
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("Error: unknown command");
			break;
		}
	}

	return 0;
}



#define MAXVAL 100 // max stack size

int sp = 0; // next free stack position
double val[MAXVAL]; // value stack

/* push: push f onto value stack */
void push(double f) {
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("Error: Stack full");
}

/* pop: pop and return top value from stack */
double pop(void) {
	if (sp > 0)
		return val[--sp];
	else {
		printf("Error: stack empty");
		return 0.0;
	}
}



#include <ctype.h> // for isdigit()

int getch(void);
void ungetch(int);

// get next operator or numeric value operand
int getop(char s[]) {
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';

	if (!isdigit(c) && c != '.')
		return c; // not a number

	i = 0;

	if (isdigit(c)) { // collect integer part
		while (isdigit(s[++i] = c = getch()))
			;
	}

	if (c == '.') { // collect fractional part
		while (isdigit(s[++i] = c = getch()))
			;
	}

	s[i] = '\0';

	if (c != EOF)
		ungetch(c);
	return NUMBER;
}



#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
{
	return (bufp > 0 ? buf[--bufp] : getchar());
}

void ungetch(int c) /* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
