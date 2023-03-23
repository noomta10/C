#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
 
int main()
{
	char a[2] ;
	char b[2];

	int i = 0;
	a[i++] = '1';
	a[i++] = '2';
	i = 0;
	b[i++] = '3';
	b[i++] = 0;
	printf("%s", a);
	int c = 2;
}