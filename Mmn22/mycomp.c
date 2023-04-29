#include "complex.h"


int main() {
	complex A = { 0, 0 };
	complex B = { 0, 0 };
	complex C = { 0, 0 };
	complex D = { 0, 0 };
	complex E = { 0, 0 };
	complex F = { 0, 0 };

	complex* complex_array[6] = {&A, &B, &C, &D, &E, &F};
	int initial_line_size = 0;
	char* line = (char*)malloc(++initial_line_size * CHAR_SIZE);
	command_line user_command_line = {NULL, 0};
	char* command;

	printf("Enter a command:\n");
	user_command_line.full_line = get_line(line, initial_line_size);

	while (strcmp(user_command_line.full_line, "stop") != 0) {
		printf("Line received is: %s\n", user_command_line.full_line);
		command = get_string(&user_command_line, ' ');
		check_command(command, &user_command_line, complex_array);
		printf("Enter a command:\n");
		user_command_line.full_line = get_line(user_command_line.full_line, initial_line_size);
		user_command_line.parse_index = 0;
	}
}


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


char* get_string(command_line* command_line, char seperator) {
	int start_string_index;
	int end_string_index;
	int final_string_size;

	/* Skip blanks and tabs */
	while (command_line->full_line[command_line->parse_index] == ' ' || command_line->full_line[command_line->parse_index] == '\t')
		(command_line->parse_index)++;
	start_string_index = command_line->parse_index;

	/* Get characters until seperator */
	while (command_line->full_line[command_line->parse_index] != seperator && command_line->full_line[command_line->parse_index] != '\0')
		(command_line->parse_index)++;
	end_string_index = command_line->parse_index;

	/* Create and allocate space for final string */
	final_string_size = end_string_index - start_string_index + 1;
	char* final_string = (char*)malloc(final_string_size);
	if (final_string == NULL) {
		printf("Error: memory allocation failed\n");
		exit(-1);
	}

	final_string = strncpy(final_string, command_line->full_line + start_string_index, final_string_size - 1);
	final_string[final_string_size - 1] = '\0';
	printf("FINAL STRING: %s\nINDEX: %d\n", final_string, command_line->parse_index);
	return final_string;
}


void check_command(char* command, command_line* user_command_line, complex complex_array[]) {
	if (strcmp(command, "read_comp") == 0) {
		check_read_comp_syntax(user_command_line, &complex_array);
	}
}

