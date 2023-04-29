#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "complex.h"

#define CHAR_SIZE sizeof(char)

typedef struct {
	double real;
	double imaginary;
} complex;

char* get_line(char* line, int line_size) {
	int c = getchar();

	while (c != '\n') {
		line[line_size - 1] = c;
		line = realloc(line, ++line_size * CHAR_SIZE);
		if (line == NULL) {
			printf("Error: memory allocation failed\n");
			exit(-1);
		}
		c = getchar();
	}
	line[line_size - 1] = '\0';

	return line;
}

void get_command(char** line_pointer) {
	int line_index = 0;
	int command_index = 0;
	int command_size = 0;
	int first_command_character;
	int last_command_character;

	char* command = (char*)malloc(++command_size * CHAR_SIZE);
	if (command == NULL) {
		printf("Error: memory allocation failed\n");
		exit(-1);
	}

	/* Skip blanks and tabs */
	while ((*line_pointer)[line_index] == ' ' || (*line_pointer)[line_index] == '\t')
		line_index++;
	first_command_character = line_index;

	/* Read command */
	while ((*line_pointer)[line_index] != ' ')
		line_index++;
	last_command_character = line_index;

	/* Allocate memory for command */
	command_size = last_command_character - first_command_character + 1;
	command = (char*)realloc(command, command_size);
	if (command == NULL) {
		printf("Error: memory allocation failed\n");
		exit(-1);
	}

	/* Put command in its variable */
	for (command_index = 0; command_index < command_size - 1; command_index++)
		command[command_index] = (*line_pointer)[first_command_character++];
	command[command_index] = '\0';

	*line_pointer += line_index;

	printf("%s\n", command);
	printf("%s\n", *line_pointer);

}


int main() {
	complex A = { 0, 0 };
	complex B = { 0, 0 };
	complex C = { 0, 0 };
	complex D = { 0, 0 };
	complex E = { 0, 0 };
	complex F = { 0, 0 };
	int initial_line_size = 0;
	char* line = (char*)malloc(++initial_line_size * CHAR_SIZE);

	printf("Enter a command:\n");
	line = allocte_line_space(line, initial_line_size);

	while (strcmp(line, "stop") != 0) {
		printf("Line received is: %s\n", line);
		get_command(&line);
		printf("MAIN: %s", line);
		printf("Enter a command:\n");
		line = get_line(line, initial_line_size);
	}
}

