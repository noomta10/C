#define _CRT_SECURE_NO_WARNINGS 
#define _GNU_SOURCE

#include <math.h> /* Provides mathematical functions */
#include <stdio.h>  /* Provides input and output functions */
#include <string.h> /* Provides functions for manipulating strings */
#include <stdlib.h> /* Provides memory allocation and deallocation functions */
#include <ctype.h> /* Provides functions for working with character data */

#define NO_ERRORS 0 /* Return value for main function- program was completed successfully */
#define COMMANDS_COUNT 9 /* Number of valid available command */
#define CHAR_SIZE sizeof(char) /* Size of a character */

typedef enum boolean {FALSE, TRUE}; /* boolean enum defines FALSE = 0 and TRUE = 1 */

/* Complex struct has 2 memebers:
1. real- a double, represents the real part of a complex number.
2. imaginary- a double, represents the imaginary part of a complex number. */
typedef struct {
	double real;
	double imaginary;
} complex;

/* command_line struct has 2 memebers:
1. full_line- a pointer of the full line the user entered.
2. parse index- an int, used to parse the full line to smaller sections on order to perform syntax check.. */
typedef struct {
	char* full_line;
	int parse_index;
} command_line;


/* Check syntax */

/* Is_number function gets a string and checks if it is a valid number. The number can be float ot negative.
If the nuber is valid, returns TRUE, else FALSE */
int is_number(char number_string[]);

/* Variable_valid function gets a char variable, and checks if its ASCII value is between A and F.
If it is in the range, it is a valid variable and the function returns 1 for TRUE, else, returns 0 for FALSE */
int variable_valid(char variable_string);

/* Get_line function gets a pointer to a line, and gets a line from the user, and reallocate space to it char by char.
In the end of the line, puts a null terminator. Returns a pointer to the complete line. */
char* get_line(char* line);

/* Get_string function gets a pointer to the stuct command line (contains a pointer to the full line and an int of the parse index) and a char of the required seperator.
the function skips blanks and tabs, and gets characters until seperator or until end of line if seperator was not found.
It moves the parse index one place after the seperator and allocate space for final string. It also puts a null terminator in the end of it.
Finally, it trims spaces and tabs from the end of the line and returns a pointer to the final string */
char* get_string(command_line* command_line, char seperator);

/* Check_command_comma function gets a pointer to the command, and checks if the command without the last char is one of the valid commands.
That way we are able to print an error message when a comma is linked to the end of the valid command name.
Returns TRUE if a comma is linked to the end of the valid command name, or FALSE if not. */
int check_command_comma(char* command);

/* Check_consecutive_commas function gets a pointer to the full line, and checks if it contains multiple consecutive commas.
Each time a comma is detected, the function checks if another comma seperated only bt spaces or tabs is present.
If there are consecutive commas in the line, the function returns TRUE, else FALSE */
int check_consecutive_commas(char* full_line);

/* Check_missing_comma function gets a pointer to the full line and an int number of required commas.
The function loops through the line and checks if the number of commas in the line is bigger or equal to the required commas count.
If it is, returns TRUE, else returns FALSE */
int check_missing_comma(char* full_line, int required_commas);

/* Main */ 
void handle_command(char* command, command_line* user_command_line, complex* complex_array[]);
void check_and_execute_read_comp(command_line* user_command_line, complex* complex_array[]);
void check_and_execute_print_comp(command_line* user_command_line, complex* complex_array[]);
void check_and_execute_add_comp(command_line* user_command_line, complex* complex_array[]);
void check_and_execute_sub_comp(command_line* user_command_line, complex* complex_array[]);
void check_and_execute_mult_comp_real(command_line * user_command_line, complex * complex_array[]);
void check_and_execute_mult_comp_img(command_line* user_command_line, complex* complex_array[]);
void check_and_execute_mult_comp_comp(command_line* user_command_line, complex* complex_array[]);
void check_and_execute_abs_comp(command_line* user_command_line, complex* complex_array[]);
int check_stop(command_line* user_command_line);

/* Complex */ 
void read_comp(complex* variable, double real, double imaginary);
void print_comp(complex variable);
complex add_comp(complex first_variable, complex second_variable);
complex sub_comp(complex first_variable, complex second_variable);
complex mult_comp_real(complex variable, double real_number);
complex mult_comp_img(complex variable, double imaginary_number);
complex mult_comp_comp(complex first_variable, complex second_variable);
double abs_comp(complex variable);
