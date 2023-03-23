#define MAX_LINE 80 /* Max line length (of the array that holds each input string) */

#define OPTION1 1 /* Options for the menu to choose the functions */
#define OPTION2 2
#define OPTION3 3
#define OPTION4 4 

#define ZERO 0 /* To reset new variables */

#define SMALL -1 /* Lexically return values of the functions my_strcmp, my_strncmp */
#define BIG 1
#define EQUAL 0
#define NOT_FOUND -1 /* Return value for the function my_strchr- if the char was not found */

#define OK 0 /* Return value for main function- the run was completed successfully */


/* My_strcmp function gets 2 strings and compare them lexically.
Returns <0 if cs<ct, 0 if cs=ct, or 0< if cs>ct. */
int my_strcmp(char cs[], char ct[]);

/* My_strncmp gets 2 strings and an integer, and compare lexically at most n characters of string cs to ct.
Returns <0 if cs<ct, 0 if cs=ct, or 0< if cs>ct. */
int my_strncmp(char cs[], char ct[], int n);

/* My_strchr gets a string and a character, and search for the first occurance of the character.
Returns int of first occurance of c in cs, or -1 if not present. */
int my_strchr(char cs[], char c);
