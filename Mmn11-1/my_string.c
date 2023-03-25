/* My_string is a program that provides various operations for strings.
The program prints a menu, lets the user choose between 3 functions and print the return value:
1. my_strcmp(cs, ct)- Gets 2 strings and compare them lexically (by ASCII value).
Returns <0 if cs<ct, 0 if cs=ct, or 0< if cs>ct.
2. my_strncmp(cs, ct, n)- Gets 2 strings and an integer, and compare lexically at most n characters of string cs to ct.
Returns <0 if cs<ct, 0 if cs=ct, or 0< if cs>ct.
3. my_strchr(cs, c)- Gets a string and a character, and search for the first occurance of the character.
Returns int of first occurance of c in cs, or -1 if not present. */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "my_string.h"

/* Main function prints a menu and lets the user choose between 3 functions. The process repeats until the user types '4' to exit.
The function is selected according to the number the user typed.
Required values are prompted, and sent to the function.
In the end, the function prints the return value of the selected function. */

int main() {
	char option[MAX_LINE];

	do {
		printf("\nChoose a function to use:\n\n"
			"1. my_strcmp(cs, ct)- Compare string cs to ct. return <0 if cs<ct, 0 if cs=ct, or 0< if cs>ct.\n\n"
			"2. my_strncmp(cs, ct, n)- Compare at most n characters of string cs to ct. return <0 if cs<ct, 0 if cs=ct, or 0< if cs>ct.\n\n"
			"3. my_strchr(cs, c)- Return int of first occurance of c in cs, or -1 if not present.\n\n"
			"4. quit\n\n"
			"Enter your choise: ");
		scanf("%[^\n]%*c", &option);

		while (strlen(option) != 1) {
			printf("Error: you need to enter a character.\nEnter your choice: ");
			scanf("%[^\n]%*c", &option);
		}

		if (option[0] == OPTION1) {
			char first_string[MAX_LINE];
			char second_string[MAX_LINE];

			printf("Enter first string: ");
			scanf("%[^\n]%*c", first_string);
			printf("Enter second string: ");
			scanf("%[^\n]%*c", second_string);

			printf("First string is: %s\nSecond string is: %s\n", first_string, second_string);
			printf("Return value: %d\n\n", my_strcmp(first_string, second_string));
		}
		else if (option[0] == OPTION2) {
			char first_string[MAX_LINE];
			char second_string[MAX_LINE];
			char characters_to_compare_line[MAX_LINE];
			int characters_to_compare;

			printf("Enter first string: ");
			scanf("%[^\n]%*c", first_string);
			printf("Enter second string: ");
			scanf("%[^\n]%*c", second_string);
			printf("Enter number of characters to compare: ");
			scanf("%[^\n]%*c", &characters_to_compare_line);
			characters_to_compare = atoi(characters_to_compare_line);

			if (characters_to_compare < 0 || characters_to_compare > MAX_LINE )
			{
				printf("Error: number of characters to compare must be a number >=0 and =<80.\n\n");
				continue;
			}

			printf("First string is: %s\nSecond string is: %s\nNumber of characters to compare is: %d\n",
				first_string, second_string, characters_to_compare);
			printf("Return value: %d\n\n", my_strncmp(first_string, second_string, characters_to_compare));
		}
		else if (option[0] == OPTION3) {
			char string[MAX_LINE];
			char character_line[MAX_LINE];
			char character;

			printf("Enter a string: ");
			scanf("%[^\n]%*c", string);
			printf("Enter a character: ");
			scanf("%[^\n]%*c", &character_line);
			character = character_line[0];


			printf("String is: %s\nCharacter is: %c\n", string, character);
			printf("Return value: %d\n\n", my_strchr(string, character));
		}
		else if (option[0] == OPTION4)
			break;
		else
			printf("Invalid option.\n\n");
	} while (option[0] != OPTION4);

	return OK;
} 


/* My_strcmp function gets 2 strings and compare them lexically. 
Returns <0 if cs<ct, 0 if cs=ct, or 0< if cs>ct. */

int my_strcmp(char cs[], char ct[]) {
	int i;
	int return_value;

	for (i = 0; cs[i] == ct[i]; i++) {
		if (cs[i] == '\0')
			return EQUAL;
	}

	return_value = (cs[i] < ct[i]) ? SMALL : BIG;
	return return_value;

}


/* My_strncmp gets 2 strings and an integer, and compare lexically at most n characters of string cs to ct. 
Returns <0 if cs<ct, 0 if cs=ct, or 0< if cs>ct. */

int my_strncmp(char cs[], char ct[], int n) {
	int i;
	int return_value;

	for (i = 0; i < n && cs[i] == ct[i] && cs[i] != '\0'; i++)
		;
		
	if (i == n || cs[i] == '\0')
		return EQUAL;

	return_value = (cs[i] < ct[i]) ? SMALL : BIG;
	return return_value;
}


/* My_strchr gets a string and a character, and search for the first occurance of the character.
Returns int of first occurance of c in cs, or -1 if not present. */

int my_strchr(char cs[], char c) {
	int i;
	for (i = 0; cs[i] != '\0'; i++) {
		if (cs[i] == c)
			return i;
	}

	return NOT_FOUND;
}
