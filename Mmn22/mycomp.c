#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <string.h>
#include "complex.h"

char* check_command(char line[]) {
	int i;
	char* valid_commands[] = {"read_comp", "print_comp", "add_comp", "sub_comp", "mult_comp_real", "mult_comp_img", "mult_comp_comp", "abs_comp"};
	int number_of_commands = sizeof(valid_commands) / sizeof(char*);
    char* command = strtok(line, " ");

	for (i = 0; i < number_of_commands; i++) {
		if (strcmp(command, valid_commands[i]) == 0) {
			return command;
		}
	}

	return "Undefined command name";
}


int main() {
	complex A = { 0, 0 };
	complex B = { 0, 0 };
	complex C = { 0, 0 };
	complex D = { 0, 0 };
	complex E = { 0, 0 };
	complex F = { 0, 0 };
	char line[100];
	char command[10];
	char variable_name;
	char first_variable_name;
	char second_variable_name;
	char line_copy[100];
	double real;
	double imaginary;

	printf("Enter a command:\n");
	scanf(" %[^\n]", line);

	while (strcmp(line, "stop") != 0) {
		printf("Line received is: %s\n", line);
		
		strcpy(line_copy, line);

		if (strcmp(check_command(line_copy), "read_comp") == 0) {
			if ((sscanf(line, "%s  %c, %lf, %lf", command, &variable_name, &real, &imaginary)) == 4)
				printf("Syntax OK.\n");
			else
				printf("Wrong syntax\n");

			if (variable_name == 'A') {
				read_comp(&A, real, imaginary);
			}
		}
		else if (strcmp(check_command(line_copy), "print_comp") == 0) {
			if ((sscanf(line, "%s %c", command, &variable_name)) == 2) {
				printf("Syntax OK.\n");
				if (variable_name == 'A') {
					print_comp(&A, real, imaginary);
				}
			}
		}
		else
			printf("Undefined command name\n");

		printf("Enter a command:\n");
		scanf(" %[^\n]", line);
	}
}

