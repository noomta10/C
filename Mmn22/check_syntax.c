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

