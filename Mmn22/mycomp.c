#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <string.h>
#include "complex.h"
typedef enum {FALSE, TRUE};


char* check_command(char line[]) {
	int i;
	int valid_command = FALSE;
	char* valid_commands[] = {"read_comp", "print_comp", "add_comp", "sub_comp", "mult_comp_real", "mult_comp_img", "mult_comp_comp", "abs_comp"};
	int number_of_commands = sizeof(valid_commands) / sizeof(char*);
    char* command = strtok(line, " ");

	for (i = 0; i < number_of_commands; i++) {
		if (strcmp(command, valid_commands[i]) == 0) {
			valid_command = TRUE;
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
	printf("Enter a command:\n");
	scanf(" %[^\n]", line);

	while (strcmp(line, "stop") != 0) {
		printf("%s\n", line);
		printf("%s\n", check_command(line));
		printf("Enter a command:\n");
		scanf(" %[^\n]", line);
	}
}

