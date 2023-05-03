#define _CRT_SECURE_NO_WARNINGS 

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CHAR_SIZE sizeof(char)

typedef struct {
	double real;
	double imaginary;
} complex;

typedef struct {
	char* full_line;
	int parse_index;
} command_line;


// Check syntax
is_number(char number_string[]);
int variable_valid(char variable_string);
char* get_line(char* line);
char* get_string(command_line* command_line, char seperator);
int handle_command(char* command, command_line* user_command_line, complex* complex_array[]);
int check_command_comma(char* command);

// Main
int check_and_execute_read_comp(command_line* user_command_line, complex* complex_array[]);
int check_and_execute_print_comp(command_line* user_command_line, complex* complex_array[]);
int check_and_execute_add_comp(command_line* user_command_line, complex* complex_array[]);
int check_and_execute_sub_comp(command_line* user_command_line, complex* complex_array[]);
int check_and_execute_mult_comp_real(command_line * user_command_line, complex * complex_array[]);
int check_and_execute_mult_comp_img(command_line* user_command_line, complex* complex_array[]);
int check_and_execute_mult_comp_comp(command_line* user_command_line, complex* complex_array[]);
int check_and_execute_abs_comp(command_line* user_command_line, complex* complex_array[]);


// Complex
void read_comp(complex* variable, double real, double imaginary);
void print_comp(complex variable);
complex add_comp(complex first_variable, complex second_variable);
complex sub_comp(complex first_variable, complex second_variable);
complex mult_comp_real(complex variable, double real_number);
complex mult_comp_img(complex variable, double imaginary_number);
complex mult_comp_comp(complex first_variable, complex second_variable);
double abs_comp(complex variable);


