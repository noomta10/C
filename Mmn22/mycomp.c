#include "complex.h"


int main() {
	complex A = { 0, 0 };
	complex B = { 0, 0 };
	complex C = { 0, 0 };
	complex D = { 0, 0 };
	complex E = { 0, 0 };
	complex F = { 0, 0 };

	complex* complex_array[6];
	command_line user_command_line = { NULL, 0 };
	char* command;
	char* line;
	int initial_line_size = 1;
	int has_EOF;

	complex_array[0] = &A;
	complex_array[1] = &B;
	complex_array[2] = &C;
	complex_array[3] = &D;
	complex_array[4] = &E;
	complex_array[5] = &F;

	line = (char*)malloc(initial_line_size * CHAR_SIZE);
	if (line == NULL) {
		printf("Error: memory allocation failed\n\n");
		exit(-1);
	}

	printf("Enter a command:\n");
	user_command_line.full_line = get_line(line);

	while (strcmp(user_command_line.full_line, "stop") != 0) {
		/* If users' input is EOF */
		if (user_command_line.full_line[0] == EOF) {
			printf("Stopping the program illegally\n\n");
			break;
		}

		has_EOF = 0;

		/* If command ends with EOF, trim and excecute it */
		if (user_command_line.full_line[strlen(user_command_line.full_line) - 1] == EOF) {
			has_EOF = 1;
			user_command_line.full_line[strlen(user_command_line.full_line) - 1] = '\0';
		}

		printf("Line received is: %s\n", user_command_line.full_line);
		command = get_string(&user_command_line, ' ');
		handle_command(command, &user_command_line, complex_array);
		user_command_line.parse_index = 0;
		printf("Enter a command:\n");

		/* If command ends with EOF, print an error and stop the program  */
		if (has_EOF) {
			printf("Stopping the program illegally\n\n");
			break;
		}

		user_command_line.full_line = get_line(user_command_line.full_line);
		if (command != NULL) {
			free(command);
		}
	}

	free(user_command_line.full_line);
	return 1;
}


void handle_command(char* command, command_line* user_command_line, complex* complex_array[]) {
	if (command == NULL) {
		printf("Missing command name\n\n");
		return;
	}
	if (!check_consecutive_commas(user_command_line->full_line)) {
		printf("Multiple consecutive commas\n\n");
		return;
	}
	if (strcmp(command, "read_comp") == 0)
		check_and_execute_read_comp(user_command_line, complex_array);
	else if (strcmp(command, "print_comp") == 0)
		check_and_execute_print_comp(user_command_line, complex_array);
	else if (strcmp(command, "add_comp") == 0)
		check_and_execute_add_comp(user_command_line, complex_array);
	else if (strcmp(command, "sub_comp") == 0)
		check_and_execute_sub_comp(user_command_line, complex_array);
	else if (strcmp(command, "mult_comp_real") == 0)
		check_and_execute_mult_comp_real(user_command_line, complex_array);
	else if (strcmp(command, "mult_comp_img") == 0)
		check_and_execute_mult_comp_img(user_command_line, complex_array);
	else if (strcmp(command, "mult_comp_comp") == 0)
		check_and_execute_mult_comp_comp(user_command_line, complex_array);
	else if (strcmp(command, "abs_comp") == 0)
		check_and_execute_abs_comp(user_command_line, complex_array);
	else if (strcmp(command, "stop") == 0) {
		if (!check_stop(user_command_line))
			return;
		else {
			free(command);
			free(user_command_line->full_line);
			exit(0);
		}
	}
	else {
		if (!check_command_comma(command)) {
			printf("Illegal comma\n\n");
			return;
		}

		printf("Undefined command name\n\n");
		return;
	}
}



void check_and_execute_read_comp(command_line* user_command_line, complex* complex_array[]) {
	int full_line_size;
	int last_index;
	char* real_input;
	char* imaginary_input;
	char variable;
	char* variable_string;

	if (!check_missing_comma(user_command_line->full_line, 2)) {
		printf("Missing comma\n\n");
		return;
	}


	if ((variable_string = get_string(user_command_line, ',')) == 0) {
		printf("Missing parameter\n\n");
		return;
	}

	variable = variable_string[0];

	full_line_size = strlen(user_command_line->full_line);
	last_index = full_line_size - 1;

	if (strlen(variable_string) > 1 || !variable_valid(variable)) {
		printf("Undefined complex variable\n\n");
		free(variable_string);
		return;
	}

	if ((real_input = get_string(user_command_line, ',')) == 0) {
		printf("Missing parameter\n\n");
		free(variable_string);
		return;
	}

	if ((imaginary_input = get_string(user_command_line, '\n')) == 0) {
		printf("Missing parameter\n\n");
		free(variable_string);
		free(real_input);
		return;
	}



	if (!is_number(real_input)) {
		printf("Invalid parameter - not a number\n\n");
		free(variable_string);
		free(real_input);
		free(imaginary_input);
		return;
	}

	if (strchr(imaginary_input, ' ') || (user_command_line->full_line[last_index]) == ',') {
		printf("Extraneous text after end of command\n\n");
		free(variable_string);
		free(real_input);
		free(imaginary_input);
		return;
	}

	if (!is_number(imaginary_input)) {
		printf("Invalid parameter - not a number\n\n");
		free(variable_string);
		free(real_input);
		free(imaginary_input);
		return;
	}





	read_comp(complex_array[variable - 'A'], (double)atof(real_input), (double)atof(imaginary_input));
	free(variable_string);
	free(real_input);
	free(imaginary_input);
}


void check_and_execute_print_comp(command_line* user_command_line, complex* complex_array[]) {
	char* variable_string;
	char variable;
	int full_line_size;
	int last_index;

	if ((variable_string = get_string(user_command_line, '\n')) == 0) {
		printf("Missing parameter\n\n");
		return;
	}

	variable = variable_string[0];
    full_line_size = strlen(user_command_line->full_line);
	last_index = full_line_size - 1;

	if (!variable_valid(variable)) {
		printf("Undefined complex variable\n\n");
		free(variable_string);
		return;
	}

	if (strchr(variable_string, ' ') || (user_command_line->full_line[last_index]) == ',') {
		printf("Extraneous text after end of command\n\n");
		free(variable_string);
		return;
	}

	if (strlen(variable_string) > 1) {
		printf("Undefined complex variable\n\n");
		free(variable_string);
		return;
	}

	print_comp(*complex_array[variable - 'A']);
	free(variable_string);
}


void check_and_execute_add_comp(command_line* user_command_line, complex* complex_array[]) {
	char variable1;
	char variable2;
	char* variable1_string;
	char* variable2_string;
	int full_line_size;
	int last_index;
	complex sum_result;

	if (!check_consecutive_commas(user_command_line->full_line)) {
		printf("Multiple consecutive commas\n\n");
		return;
	}

	if ((variable1_string = get_string(user_command_line, ',')) == 0) {
		printf("Missing parameter\n\n");
		return;
	}

	if ((variable2_string = get_string(user_command_line, '\n')) == 0) {
		printf("Missing parameter\n\n");
		free(variable1_string);
		return;
	}

	variable1 = variable1_string[0];
	variable2 = variable2_string[0];
	full_line_size = strlen(user_command_line->full_line);
	last_index = full_line_size - 1;

	/* Check variable 1 */
	if (!variable_valid(variable1) || strlen(variable1_string) > 1) {
		printf("Undefined complex variable\n\n");
		free(variable1_string);
		free(variable2_string);
		return;
	}

	/* Check variable 2 */
	if (!variable_valid(variable2)) {
		printf("Undefined complex variable\n\n");
		free(variable1_string);
		free(variable2_string);
		return;
	}

	if (strchr(variable2_string, ' ') || (user_command_line->full_line[last_index]) == ',') {
		printf("Extraneous text after end of command\n\n");
		free(variable1_string);
		free(variable2_string);
		return;
	}

	if (strlen(variable2_string) > 1) {
		printf("Undefined complex variable\n\n");
		free(variable1_string);
		free(variable2_string);
		return;
	}

	sum_result = add_comp(*complex_array[variable1 - 'A'], *complex_array[variable2 - 'A']);
	print_comp(sum_result);
	free(variable1_string);
	free(variable2_string);
}


void check_and_execute_sub_comp(command_line* user_command_line, complex* complex_array[]) {
	int full_line_size;
	int last_index;
	char variable1;
	char variable2;
	char* variable1_string;
	char* variable2_string;
	complex sub_result;

	if (!check_consecutive_commas(user_command_line->full_line)) {
		printf("Multiple consecutive commas\n\n");
		return;
	}

	if ((variable1_string = get_string(user_command_line, ',')) == 0) {
		printf("Missing parameter\n\n");
		return;
	}

	if ((variable2_string = get_string(user_command_line, '\n')) == 0) {
		printf("Missing parameter\n\n");
		free(variable1_string);
		return;
	}

	variable1 = variable1_string[0];
	variable2 = variable2_string[0];

	full_line_size = strlen(user_command_line->full_line);
	last_index = full_line_size - 1;

	/* Check variable 1 */
	if (!variable_valid(variable1) || strlen(variable1_string) > 1) {
		printf("Undefined complex variable\n\n");
		free(variable1_string);
		free(variable2_string);
		return;
	}

	/* Check variable 2 */
	if (!variable_valid(variable2)) {
		printf("Undefined complex variable\n\n");
		free(variable1_string);
		free(variable2_string);
		return;
	}

	if (strchr(variable2_string, ' ') || (user_command_line->full_line[last_index]) == ',') {
		printf("Extraneous text after end of command\n\n");
		free(variable1_string);
		free(variable2_string);
		return;
	}

	if (strlen(variable2_string) > 1) {
		printf("Undefined complex variable\n\n");
		free(variable1_string);
		free(variable2_string);
		return;
	}

	sub_result = sub_comp(*complex_array[variable1 - 'A'], *complex_array[variable2 - 'A']);
	print_comp(sub_result);
	free(variable1_string);
	free(variable2_string);
}


void check_and_execute_mult_comp_real(command_line* user_command_line, complex* complex_array[]) {
	int full_line_size;
	int last_index;
	char* variable_string;
	char variable;
	char* real_input;
	complex mult_result;

	if (!check_consecutive_commas(user_command_line->full_line)) {
		printf("Multiple consecutive commas\n\n");
		return;
	}

	if ((variable_string = get_string(user_command_line, ',')) == 0) {
		printf("Missing parameter\n\n");
		return;
	}

	variable = variable_string[0];
	full_line_size = strlen(user_command_line->full_line);
	last_index = full_line_size - 1;

	/* Check variable */
	if (!variable_valid(variable) || strlen(variable_string) > 1) {
		printf("Undefined complex variable\n\n");
		free(variable_string);
		return;
	}

	/* Check number */
	if ((real_input = get_string(user_command_line, '\n')) == 0) {
		printf("Missing parameter\n\n");
		free(variable_string);
		return;
	}

	if (strchr(real_input, ' ') || (user_command_line->full_line[last_index]) == ',') {
		printf("Extraneous text after end of command\n\n");
		free(variable_string);
		free(real_input);
		return;
	}

	if (!is_number(real_input)) {
		printf("Invalid parameter - not a number\n\n");
		free(variable_string);
		free(real_input);
		return;
	}

	mult_result = mult_comp_real(*complex_array[variable - 'A'], atof(real_input));
	print_comp(mult_result);
	free(variable_string);
	free(real_input);
}


void check_and_execute_mult_comp_img(command_line* user_command_line, complex* complex_array[]) {
	int full_line_size;
	int last_index;
	char* variable_string;
	char variable;
	char* imaginary_input;
	complex mult_result;

	if (!check_consecutive_commas(user_command_line->full_line)) {
		printf("Multiple consecutive commas\n\n");
		return;
	}

	if ((variable_string = get_string(user_command_line, ',')) == 0) {
		printf("Missing parameter\n\n");
		return;
	}

	variable = variable_string[0];
	
	full_line_size = strlen(user_command_line->full_line);
	last_index = full_line_size - 1;

	/* Check variable */
	if (!variable_valid(variable) || strlen(variable_string) > 1) {
		printf("Undefined complex variable\n\n");
		free(variable_string);
		return;
	}

	/* Check number */
	if ((imaginary_input = get_string(user_command_line, '\n')) == 0) {
		printf("Missing parameter\n\n");
		free(variable_string);
		return;
	}

	if (strchr(imaginary_input, ' ') || (user_command_line->full_line[last_index]) == ',') {
		printf("Extraneous text after end of command\n\n");
		free(variable_string);
		free(imaginary_input);
		return;
	}

	if (!is_number(imaginary_input)) {
		printf("Invalid parameter - not a number\n\n");
		free(variable_string);
		free(imaginary_input);
		return;
	}

	mult_result = mult_comp_img(*complex_array[variable - 'A'], atof(imaginary_input));
	print_comp(mult_result);
	free(variable_string);
	free(imaginary_input);
}


void check_and_execute_mult_comp_comp(command_line* user_command_line, complex* complex_array[]) {
	char variable1;
	char variable2;
	char* variable1_string;
	char* variable2_string;
	int full_line_size;
	int last_index;
	complex mult_result;

	if (!check_consecutive_commas(user_command_line->full_line)) {
		printf("Multiple consecutive commas\n\n");
		return;
	}

	if ((variable1_string = get_string(user_command_line, ',')) == 0) {
		printf("Missing parameter\n\n");
		return;
	}

	if ((variable2_string = get_string(user_command_line, '\n')) == 0) {
		printf("Missing parameter\n\n");
		free(variable1_string);
		return;
	}

	variable1 = variable1_string[0];
	variable2 = variable2_string[0];

	full_line_size = strlen(user_command_line->full_line);
	last_index = full_line_size - 1;

	/* Check variable 1 */
	if (!variable_valid(variable1) || strlen(variable1_string) > 1) {
		printf("Undefined complex variable\n\n");
		free(variable1_string);
		free(variable2_string);
		return;
	}

	/* Check variable 2 */
	if (!variable_valid(variable2)) {
		printf("Undefined complex variable\n\n");
		free(variable1_string);
		free(variable2_string);
		return;
	}

	if (strchr(variable2_string, ' ') || (user_command_line->full_line[last_index]) == ',') {
		printf("Extraneous text after end of command\n\n");
		free(variable1_string);
		free(variable2_string);
		return;
	}

	if (strlen(variable2_string) > 1) {
		printf("Undefined complex variable\n\n");
		free(variable1_string);
		free(variable2_string);
		return;
	}

	mult_result = mult_comp_comp(*complex_array[variable1 - 'A'], *complex_array[variable2 - 'A']);
	print_comp(mult_result);
	free(variable1_string);
	free(variable2_string);
}


void check_and_execute_abs_comp(command_line* user_command_line, complex* complex_array[]) {
	double abs_result;
	char* variable_string;
	char variable;
	int full_line_size;
	int last_index;

	if ((variable_string = get_string(user_command_line, '\n')) == 0) {
		printf("Missing parameter\n\n");
		return;
	}

	variable = variable_string[0];
	full_line_size = strlen(user_command_line->full_line);
	last_index = full_line_size - 1;

	if (!variable_valid(variable)) {
		printf("Undefined complex variable\n\n");
		free(variable_string);
		return;
	}

	if (strchr(variable_string, ' ') || (user_command_line->full_line[last_index]) == ',') {
		printf("Extraneous text after end of command\n\n");
		free(variable_string);
		return;
	}

	if (strlen(variable_string) > 1) {
		printf("Undefined complex variable\n\n");
		free(variable_string);
		return;
	}

	abs_result = abs_comp(*complex_array[variable - 'A']);
	printf("%.2f\n", abs_result);
	free(variable_string);
}


int check_stop(command_line* user_command_line) {
	char* ending_characters = get_string(user_command_line, '\n');

	if (ending_characters){
		printf("Extraneous text after end of command\n\n");
		free(ending_characters);
		return 0;
	}

	free(ending_characters);
	return 1;
}
