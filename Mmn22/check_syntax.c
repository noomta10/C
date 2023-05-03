#include "complex.h"

int variable_valid(char variable) {
	int index;
	int valid_variable = 0;
	char valid_variables[6] = { 'A', 'B', 'C', 'D', 'E', 'F' };

;
	for (index = 0; index < 6; index++) {
		if (variable == valid_variables[index])
			valid_variable = 1;
	}

	if (!valid_variable) {
		return 0;
	}

	return 1;
}

is_number(char number_string[]) {
	int i;
	int dots_count = 0;

	for (i = 0; i < strlen(number_string); i++) {
		if ((number_string[i]) == '.')
			dots_count++;
		if (!isdigit(number_string[i]) && !(dots_count == 1 && number_string[i] == '.') && !(number_string[i] == ' '))
			return 0;
	}

	return 1;
}


char* get_line(char* line) {
	int line_size = 1;
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

	/* Move one index after the seperator */
	(command_line->parse_index)++;

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


int check_command_comma(char* command) {
	int valid_command = 0;
	int i;
	char* valid_commands[] = { "read_comp", "print_comp", "add_comp", "sub_comp", "mult_comp_real", "mult_comp_img", "mult_comp_comp", "abs_comp", "stop" };
	int number_of_commands = 9;
	int command_length = strlen(command);
	int command_last_index = command_length - 1;

	char* command_without_last_character = malloc(command_length);
	if (command_without_last_character == NULL) {
		printf("Error: memory allocation failed\n");
		exit(-1);
	}

	strncpy(command_without_last_character, command, command_length - 1);
	command_without_last_character[command_length - 1] = '\0';

	for (i = 0; i < number_of_commands; i++) {
		if (strcmp(command_without_last_character, valid_commands[i]) == 0) {
			valid_command = 1;
			break;
		}
	}

	if (command[command_last_index] == ',' && valid_command) {
		free(command_without_last_character);
		return 0;
	}

	free(command_without_last_character);
	return 1;
}