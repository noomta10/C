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

typedef enum {A, B, C, D, E, F} variables_indexes;

char* get_line(char* line, int line_size);
char* get_string(command_line* command_line, char seperator);
void check_command(char* command, command_line* user_command_line, complex complex_array[]);
void check_read_comp_syntax(command_line* user_command_line, complex* complex_array[]);
int variable_valid(char variable);