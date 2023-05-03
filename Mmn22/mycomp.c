#include "complex.h"


int main() {
	complex A = { 0, 0 };
	complex B = { 0, 0 };
	complex C = { 0, 0 };
	complex D = { 0, 0 };
	complex E = { 0, 0 };
	complex F = { 0, 0 };

	command_line user_command_line = { NULL, 0 };
	char* command;
	int initial_line_size = 1;
	char* line = (char*)malloc(initial_line_size * CHAR_SIZE);
	if (line == NULL) {
		printf("Error: memory allocation failed\n");
		exit(-1);
	}

	complex* complex_array[6] = {&A, &B, &C, &D, &E, &F};
	printf("Enter a command:\n");
	user_command_line.full_line = get_line(line);

	while (strcmp(user_command_line.full_line, "stop") != 0) {
		printf("Line received is: %s\n", user_command_line.full_line);
		command = get_string(&user_command_line, ' ');
		handle_command(command, &user_command_line, complex_array);
		user_command_line.parse_index = 0;
		printf("Enter a command:\n");
		user_command_line.full_line = get_line(user_command_line.full_line);
	}
}


int handle_command(char* command, command_line* user_command_line, complex* complex_array[]) {
	int valid_command = 0;
	int i;
	char* valid_commands[] = {"read_comp", "print_comp", "add_comp", "sub_comp", "mult_comp_real", "mult_comp_img", "mult_comp_comp", "abs_comp", "stop"};
	int command_length = strlen(command);
	int command_last_index = command_length - 1;

	char* command_without_last_character = malloc(command_length);
	if (command_without_last_character == NULL) {
		printf("Error: memory allocation failed\n");
		exit(-1);
	}

	strcpy(command_without_last_character, command, command_length - 1);
	command_without_last_character[command_length - 1] = '\0';

	if (strcmp(command, "read_comp") == 0) {
		if (!check_and_execute_read_comp(user_command_line, complex_array))
			return 0;
	}
	else if (strcmp(command, "print_comp") == 0) {
		if (!check_and_execute_print_comp(user_command_line, complex_array))
			return 0;
	}
	else if (strcmp(command, "add_comp") == 0) {
		if (!check_and_execute_add_comp(user_command_line, complex_array))
			return 0;
	}
	else if (strcmp(command, "sub_comp") == 0) {
		if (!check_and_execute_sub_comp(user_command_line, complex_array))
			return 0;
	}
	else if (strcmp(command, "mult_comp_real") == 0) {
		if (!check_and_execute_mult_comp_real(user_command_line, complex_array))
			return 0;
	}
	else if (strcmp(command, "mult_comp_img") == 0) {
		if (!check_and_execute_mult_comp_img(user_command_line, complex_array))
			return 0;
	}
	else if (strcmp(command, "mult_comp_comp") == 0) {
		if (!check_and_execute_mult_comp_comp(user_command_line, complex_array))
			return 0;
	}
	else if (strcmp(command, "abs_comp") == 0) {
		if (!check_and_execute_abs_comp(user_command_line, complex_array))
			return 0;
	}
	else {
		for (i = 0; i <= command_last_index; i++) {
			if (strcmp(command_without_last_character, valid_commands[i]) == 0) {
				valid_command = 1;
				break;
			}
		}
		//free(command_without_last_character);

		if (command[command_last_index] == ',' && valid_command) {
			printf("Illegal comma\n");
			return 0;
		}

		printf("Invalid command\n");
		return 0;
	}
}


int check_and_execute_read_comp(command_line* user_command_line, complex* complex_array[]) {
	char* real_input;
	char* imaginary_input;
	char* variable_string = get_string(user_command_line, ',');
	char variable_character = variable_string[0];	
	int full_line_size = strlen(user_command_line->full_line);
	int last_index = full_line_size - 1;

	// If variable is invalid, return 0
	if (strlen(variable_string) > 1 || !variable_valid(variable_character)) {
		printf("Undefined complex variable\n");
		return 0;
	}

	real_input = get_string(user_command_line, ',');
	imaginary_input = get_string(user_command_line, '\n');

	if (!is_number(real_input)) {
		printf("Invalid parameter \- not a number\n");
		return 0;
	}

	if (strchr(imaginary_input, ' ') || (user_command_line->full_line[last_index]) == ',') {
		printf("Extraneous text after end of command\n");
		return 0;
	}

	if (!is_number(imaginary_input)) {
		printf("Invalid parameter \- not a number\n");
		return 0;
	}

	read_comp(complex_array[variable_character - 'A'], (double)atof(real_input), (double)atof(imaginary_input));
	return 1;
}


int check_and_execute_print_comp(command_line* user_command_line, complex* complex_array[]) {
	char* variable_string = get_string(user_command_line, ',');
	char variable_character = variable_string[0];
	int full_line_size = strlen(user_command_line->full_line);
	int last_index = full_line_size - 1;

	// If variable is invalid, return 0
	if (!variable_valid(variable_character)) {
		printf("Undefined complex variable\n");
		return 0;
	}

	if (strchr(variable_string, ' ') || (user_command_line->full_line[last_index]) == ',') {
		printf("Extraneous text after end of command\n");
		return 0;
	}

	if (strlen(variable_string) > 1) {
		printf("Undefined complex variable\n");
		return 0;
	}

	print_comp(*complex_array[variable_character - 'A']);
}


int check_and_execute_add_comp(command_line* user_command_line, complex* complex_array[]) {
	char* variable_string1 = get_string(user_command_line, ',');
	char variable1 = variable_valid(variable_string1);
	char* variable_string2 = get_string(user_command_line, '\n');
	char variable2 = variable_valid(variable_string2);

	complex sum_result = add_comp(*complex_array[variable1 - 'A'], *complex_array[variable2 - 'A']);
	print_comp(sum_result);
}


int check_and_execute_sub_comp(command_line* user_command_line, complex* complex_array[]) {
	char* variable_string1 = get_string(user_command_line, ',');
	char variable1 = variable_valid(variable_string1);
	char* variable_string2 = get_string(user_command_line, '\n');
	char variable2 = variable_valid(variable_string2);

	complex sub_result = sub_comp(*complex_array[variable1 - 'A'], *complex_array[variable2 - 'A']);
	print_comp(sub_result);
}


int check_and_execute_mult_comp_real(command_line* user_command_line, complex* complex_array[]) {
	char* variable_string = get_string(user_command_line, ',');
	char variable = variable_valid(variable_string);
	double real_input = atof(get_string(user_command_line, '\n'));

	complex mult_result = mult_comp_real(*complex_array[variable - 'A'], real_input);
	print_comp(mult_result);
}


int check_and_execute_mult_comp_img(command_line* user_command_line, complex* complex_array[]) {
	char* variable_string = get_string(user_command_line, ',');
	char variable = variable_valid(variable_string);
	double img_input = atof(get_string(user_command_line, '\n'));

	complex mult_result = mult_comp_img(*complex_array[variable - 'A'], img_input);
	print_comp(mult_result);
}


int check_and_execute_mult_comp_comp(command_line* user_command_line, complex* complex_array[]) {
	char* variable_string1 = get_string(user_command_line, ',');
	char variable1 = variable_valid(variable_string1);
	char* variable_string2 = get_string(user_command_line, '\n');
	char variable2 = variable_valid(variable_string2);

	complex mult_result = mult_comp_comp(*complex_array[variable1 - 'A'], *complex_array[variable2 - 'A']);
	print_comp(mult_result);
}


int check_and_execute_abs_comp(command_line* user_command_line, complex* complex_array[]) {
	char* variable_string = get_string(user_command_line, ',');
	char variable = variable_valid(variable_string);

	double abs_result = abs_comp(*complex_array[variable - 'A']);
	printf("%.2lf\n", abs_result);
}