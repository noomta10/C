#include "complex.h"


/* Variable_valid function gets a char variable, and checks if its ASCII value is between A and F.
If it is in the range, it is a valid variable and the function returns 1 for TRUE, else, returns 0 for FALSE */
int variable_valid(char variable) {
	return (variable >= 'A' && variable <= 'F');
}


/* Is_number function gets a string and checks if it is a valid number. The number can be float ot negative.  
If the nuber is valid, returns TRUE, else FALSE */
int is_number(char number_string[]) {
	int i = 0;
	int points_count = 0;

	/* Skip spaces and tabs */
	while (number_string[i] == '\t' || number_string[i] == ' ')
		i++;

	/* Accept minus */
	if (number_string[i] == '-')
		i++;

	/* Check number validity */
	for (; i < strlen(number_string); i++) {
		if ((number_string[i]) == '.')
			points_count++;
		if (points_count > 1)
			return FALSE;
		if ((!isdigit(number_string[i]) && points_count > 1) || (!isdigit(number_string[i]) && number_string[i] != '.'))
			return FALSE;
	}

	return TRUE;
}


/* Get_line function gets a pointer to a line, and gets a line from the user, and reallocate space to it char by char.
In the end of the line, puts a null terminator. Returns a pointer to the complete line. */
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

		if (c == EOF) {
			break;
		}

		c = getchar();

	}
	line[line_size - 1] = '\0';
	return line;
}


/* Get_string function gets a pointer to the stuct command line (contains a pointer to the full line and an int of the parse index) and a char of the required seperator.
the function skips blanks and tabs, and gets characters until seperator or until end of line if seperator was not found.
It moves the parse index one place after the seperator and allocate space for final string. It also puts a null terminator in the end of it.
Finally, it trims spaces and tabs from the end of the line and returns a pointer to the final string */
char* get_string(command_line* command_line, char seperator) {
	int start_string_index;
	int end_string_index;
	int final_string_size;
	int i;
	char* final_string;

	/* Skip blanks and tabs */
	while (command_line->full_line[command_line->parse_index] == ' ' || command_line->full_line[command_line->parse_index] == '\t')
		(command_line->parse_index)++;
	start_string_index = command_line->parse_index;

	/* Sign that a parameter is missing */
	if ((command_line->full_line[start_string_index]) == '\0')
		return NULL;

	/* Get characters until seperator or until end of line if seperator was not found */
	while (command_line->full_line[command_line->parse_index] != seperator && command_line->full_line[command_line->parse_index] != '\0')
		(command_line->parse_index)++;
	end_string_index = command_line->parse_index;

	/* Move one index after the seperator */
	if (command_line->full_line[command_line->parse_index] == seperator)
		(command_line->parse_index)++;

	/* Create and allocate space for final string */
	final_string_size = end_string_index - start_string_index + 1;
	final_string = (char*)malloc(final_string_size);
	if (final_string == NULL) {
		printf("Error: memory allocation failed\n");
		exit(-1);
	}

	strncpy(final_string, command_line->full_line + start_string_index, final_string_size - 1);
	final_string[final_string_size - 1] = '\0';

	/* Trim spaces and tabs from the end of the line */
	if (seperator != ' ') {
		for (i = strlen(final_string) - 1; i >= 0; i--) {
			if (final_string[i] == '\t' || final_string[i] == ' ')
				final_string[i] = '\0';
			else
				break;
		}
	}

	printf("DEBUG: Final string: %s Index: %d\n", final_string, command_line->parse_index);
	return final_string;
}


/* Check_command_comma function gets a pointer to the command, and checks if the command without the last char is one of the valid commands.
That way we are able to print an error message when a comma is linked to the end of the valid command name.
Returns TRUE if a comma is linked to the end of the valid command name, or FALSE if not. */
int check_command_comma(char* command) {
	int valid_command = 0;
	int i;
	char* valid_commands[] = { "read_comp", "print_comp", "add_comp", "sub_comp", "mult_comp_real", "mult_comp_img", "mult_comp_comp", "abs_comp", "stop" };
	int command_length = strlen(command);
	int command_last_index = command_length - 1;
	char* command_without_last_character = malloc(command_length);
	if (command_without_last_character == NULL) {
		printf("Error: memory allocation failed\n");
		exit(-1);
	}

	strncpy(command_without_last_character, command, command_length - 1);
	command_without_last_character[command_length - 1] = '\0';

	for (i = 0; i < COMMANDS_COUNT; i++) {
		if (strcmp(command_without_last_character, valid_commands[i]) == 0) {
			valid_command = 1;
			break;
		}
	}

	if (command[command_last_index] == ',' && valid_command) {
		free(command_without_last_character);
		return TRUE;
	}

	free(command_without_last_character);
	return FALSE;
}


/* Check_consecutive_commas function gets a pointer to the full line, and checks if it contains multiple consecutive commas.
Each time a comma is detected, the function checks if another comma seperated only bt spaces or tabs is present.
If there are consecutive commas in the line, the function returns TRUE, else FALSE */
int check_consecutive_commas(char* full_line) {
	int commas_count = 0;
	int i = 0;

	for (i = 0; i < strlen(full_line); i++) {
		if (full_line[i] == ',') {
			commas_count++;
			if (commas_count > 1)
				return TRUE;
		}
		else if (full_line[i] != ' ' && full_line[i] != '\t') {
			commas_count = 0;
		}
	}

	return FALSE;
}


/* Check_missing_comma function gets a pointer to the full line and an int number of required commas.
The function loops through the line and checks if the number of commas in the line is bigger or equal to the required commas count.
If it is, returns TRUE, else returns FALSE */
int check_missing_comma(char* full_line, int required_commas) {
	int i;
	int commas_count = 0;
	
	for (i = 0; i < strlen(full_line); i++) {
		if (full_line[i] == ',')
			commas_count++;
	}

	if (commas_count >= required_commas)
		return TRUE;
	return FALSE;
}
