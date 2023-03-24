#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
 
int main()
{
	char first_string[80];
	char second_string[80];

	printf("Enter first string: ");
	scanf("%[^\n]%*c", first_string);
	 printf("Enter second string: ");
	 scanf("%[^\n]%*c", second_string);

	printf("First string is: %s, Second string is: %s.\n", first_string, second_string);
}