#include <stdio.h>

void printd(int);

int main() {
	printd(123);
}

void printd(int number)
{
	if (number / 10)
		printd(number / 10);
	putchar(number % 10 + '0');
}
