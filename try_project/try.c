#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
 
int main()
{
	int option;
	printf("\nChoose a function to use:\n\n"
		"1. my_strcmp(cs, ct)- Compare string cs to ct. return <0 if cs<ct, 0 if cs=ct, or 0< if cs>ct.\n\n"
		"2. my_strncmp(cs, ct, n)- Compare at most n characters of string cs to ct. return <0 if cs<ct, 0 if cs=ct, or 0< if cs>ct.\n\n"
		"3. my_strchr(cs, c)- Return int of first occurance of c in cs, or -1 if not present.\n\n"
		"4. quit\n\n"
		"Enter your choise: ");
	scanf("%d%*c", &option);

	if (option == 1) {
		char first_string[80];
		char second_string[80];

		printf("Enter first string: ");
		scanf("%[^\n]%*c", first_string);
		printf("Enter second string: ");
		scanf("%[^\n]%*c", second_string);

		printf("First string is: %s\nSecond string is: %s\n", first_string, second_string);
	}
}