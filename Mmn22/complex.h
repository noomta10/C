#define _CRT_SECURE_NO_WARNINGS 
#define _GNU_SOURCE

#include <math.h> /* Provides mathematical functions */
#include <stdio.h>  /* Provides input and output functions */
#include <string.h> /* Provides functions for manipulating strings */
#include <stdlib.h> /* Provides memory allocation and deallocation functions */
#include <ctype.h> /* Provides functions for working with character data */

#define ONE_CHARACTER 1 /* Length of a string of one character */
#define TWO_COMMAS 2 /* The function syntax has 2 commas */
#define GET_STRING_FAILED 0 /* When the function get_string fails, it returns NULL */
#define ONE_COMMA 1 /* The function syntax has 1 comma */
#define ONE_INDEX 1 /* For Trimming strings sizes */
#define STRINGS_EQUALS 0 /* Sign that the strings are equal */
#define MEMORY_ERROR -1 /* Return value for memory reallocate or dealllocate error */
#define INITIAL_SIZE 1 /* Initial size of a pointer */
#define INITIAL_ZERO 0 /* Zero for initializing variables */
#define ONE_POINT 1 /* In order to check if the number is float and has a point */
#define VARIABLES_COUNT 6 /* Number of variables */
#define NO_ERRORS 0 /* Return value for main function- program was completed successfully */
#define COMMANDS_COUNT 9 /* Number of valid available command */
#define CHAR_SIZE sizeof(char) /* Size of a character */

typedef enum {FALSE, TRUE} boolean; /* boolean enum defines FALSE = 0 and TRUE = 1 */
typedef enum {INDEX1, INDEX2, INDEX3, INDEX4, INDEX5, INDEX6} indexes; /* Indexes of the complex array */

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

/* Handle_command function gets a pointer to the command, a struct to the user cimmand line (contains the full line pointer and an int number of parse index),
and an array of pointers to structs from type complex.
First, it checks if the command name is NULL, if it is, it prints an error message and exit.
Then, it calls check_consecutive_commas function, if there are multiple consecutive commas, it prints an error message and exit.
After that it checks what the received command is, then refers to the appropriate function that handles that command.
Finally, if the command did not match to any of the valid commands, it prints an appropriate error message and exit. */
void handle_command(char* command, command_line* user_command_line, complex* complex_array[]);

/* Check_and_execute_read_comp function gets a pointer to a struct of the user command line (contains the full line received, and an int number of parse index),
and an array of pointers to structs from complex type.
It uses the get_string function to parse the full row string to get the desired parameter whenever it needs one.
If it fails to get the desired parameter, it prints an appropriate error message, frees the allocated memory space, and exits the function.
Otherwise, it calls the read_comp function with the necessary parameters. */
void check_and_execute_read_comp(command_line* user_command_line, complex* complex_array[]);

/* Check_and_execute_print_comp function gets a pointer to a struct of the user command line (contains the full line received, and an int number of parse index),
and an array of pointers to structs from complex type.
It uses the get_string function to parse the full row string to get the variable name.
If it fails to get it, it prints an appropriate error message, frees the allocated memory space, and exits the function.
Otherwise, it calls the print_comp function with the defined variable. */
void check_and_execute_print_comp(command_line* user_command_line, complex* complex_array[]);

/* Check_and_execute_add_comp function gets a pointer to a struct of the user command line (contains the full line received, and an int number of parse index),
and an array of pointers to structs from complex type.
It uses the get_string function to parse the full row string to get the variables name.
If it fails to get them, it prints an appropriate error message, frees the allocated memory space, and exits the function.
Otherwise, it calls the add_comp function with the defined variables and prints the sum result. */
void check_and_execute_add_comp(command_line* user_command_line, complex* complex_array[]);

/* Check_and_execute_sub_comp function gets a pointer to a struct of the user command line (contains the full line received, and an int number of parse index),
and an array of pointers to structs from complex type.
It uses the get_string function to parse the full row string to get the variables name.
If it fails to get them, it prints an appropriate error message, frees the allocated memory space, and exits the function.
Otherwise, it calls the sub_comp function with the defined variables and prints the subtraction result. */
void check_and_execute_sub_comp(command_line* user_command_line, complex* complex_array[]);

/* Check_and_execute_mult_comp_real function gets a pointer to a struct of the user command line (contains the full line received, and an int number of parse index),
and an array of pointers to structs from complex type.
It uses the get_string function to parse the full row string to get the variable name and the real number.
If it fails to get them, it prints an appropriate error message, frees the allocated memory space, and exits the function.
Otherwise, it calls the mult_comp_real function with the necessary parameters and prints the multiplication result. */
void check_and_execute_mult_comp_real(command_line * user_command_line, complex * complex_array[]);

/* Check_and_execute_mult_comp_img function gets a pointer to a struct of the user command line (contains the full line received, and an int number of parse index),
and an array of pointers to structs from complex type.
It uses the get_string function to parse the full row string to get the variable name and the imaginary number.
If it fails to get them, it prints an appropriate error message, frees the allocated memory space, and exits the function.
Otherwise, it calls the mult_comp_img function with the necessary parameters and prints the multiplication result. */
void check_and_execute_mult_comp_img(command_line* user_command_line, complex* complex_array[]);

/* Check_and_execute_mult_comp_comp function gets a pointer to a struct of the user command line (contains the full line received, and an int number of parse index),
and an array of pointers to structs from complex type.
It uses the get_string function to parse the full row string to get the variables name.
If it fails to get them, it prints an appropriate error message, frees the allocated memory space, and exits the function.
Otherwise, it calls the mult_comp_comp function with the variables and prints the multiplication result. */
void check_and_execute_mult_comp_comp(command_line* user_command_line, complex* complex_array[]);

/* Check_and_execute_abs_comp function gets a pointer to a struct of the user command line (contains the full line received, and an int number of parse index),
and an array of pointers to structs from complex type.
It uses the get_string function to parse the full row string to get the variable name.
If it fails to get it, it prints an appropriate error message, frees the allocated memory space, and exits the function.
Otherwise, it calls the abs_comp function with the variable and prints the absolute result. */
void check_and_execute_abs_comp(command_line* user_command_line, complex* complex_array[]);

/* Check_stop function gets a command_line pointer to the user command line.
It checks if the characters after the command are spaces or tabs.
If they are not, prints an appropriate error message, frees the allocated memory space, and returns FALSE.
Else, it frees the allocated memory space returns TRUE.  */
int check_stop(command_line* user_command_line);

/* Complex */ 

/* Read_comp function gets a pointer to a complex variable, a double real number and a double imaginary number.
It puts the real and the double part in their respective addresss in the complex variable pointer. */
void read_comp(complex* variable, double real, double imaginary);

/* Print_comp function gets a complex variable, and print its real and imaginary members in a formatted way. */
void print_comp(complex variable);

/* Add_comp function gets 2 complex variables and add the real part and the imaginary part of each of them.
Returns a complex number of the sum result */
complex add_comp(complex first_variable, complex second_variable);

/* Sud_comp function gets 2 complex variables and subtract the real part and the imaginary part of each of them.
Returns a complex number of the difference result */
complex sub_comp(complex first_variable, complex second_variable);

/* Mult_comp_real function gets a complex variable and a double real number, and multiple each member with the real number.
Returns a complex number of the product result */
complex mult_comp_real(complex variable, double real_number);

/* Mult_comp_img function gets a complex variable and a double imaginary number, and multiple each member with the imaginary number.
Returns a complex number of the product result */
complex mult_comp_img(complex variable, double imaginary_number);

/* Mult_comp_comp function gets 2 complex variable and calculate their product.
Returns a complex number of the product result */
complex mult_comp_comp(complex first_variable, complex second_variable);

/* Abs_comp function gets a complex variable and calculates its absolute value.
Returns a double number of the absolute result */
double abs_comp(complex variable);
