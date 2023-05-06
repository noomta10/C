#include "complex.h"


int main() {
	complex A = { 0, 0 };
	complex B = { 0, 0 };
	complex C = { 0, 0 };
	complex D = { 0, 0 };
	complex E = { 0, 0 };
	complex F = { 0, 0 };

	complex* complex_array[6];
	complex_array[0] = &A;
	complex_array[1] = &B;
	complex_array[2] = &C;
	complex_array[3] = &D;
	complex_array[4] = &E;
	complex_array[5] = &F;

	command_line user_command_line = { NULL, 0 };
	char* command;
	int initial_line_size = 1;
	char* line = (char*)malloc(initial_line_size * CHAR_SIZE);
	if (line == NULL) {
		printf("Error: memory allocation failed\n\n");
		exit(-1);
	}

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

	free(line);
	return 1;
}


int handle_command(char* command, command_line* user_command_line, complex* complex_array[]) {
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
	else if (strcmp(command, "stop") == 0) {
		if (!check_stop(user_command_line))
			return 0;
		else
			exit(0);
	}
	else {
		if (strlen(command) == 0) {
			printf("Undefined command name\n\n");
			return 0;
		}
		if (!check_command_comma(command)) {
			printf("Illegal comma\n\n");
			return 0;
	    }

		printf("Undefined command name\n\n");
		return 0;
	}
	return 1;
}


int check_and_execute_read_comp(command_line* user_command_line, complex* complex_array[]) {
	int full_line_size;
	int last_index;
	char* real_input;
	char* imaginary_input;
	char variable;
	char* variable_string;

	if ((variable_string = get_string(user_command_line, ',')) == 0) {
		printf("Missing parameter\n\n");
		return 0;
	}

	variable = variable_string[0];

	full_line_size = strlen(user_command_line->full_line);
	last_index = full_line_size - 1;

	if (strlen(variable_string) > 1 || !variable_valid(variable)) {
		printf("Undefined complex variable\n\n");
		return 0;
	}

	if ((real_input = get_string(user_command_line, ',')) == 0) {
		printf("Missing parameter\n\n");
		return 0;
	}

	if ((imaginary_input = get_string(user_command_line, '\n')) == 0) {
		printf("Missing parameter\n\n");
		return 0;
	}

	if (!is_number(real_input)) {
		printf("Invalid parameter - not a number\n\n");
		return 0;
	}

	if (strchr(imaginary_input, ' ') || (user_command_line->full_line[last_index]) == ',') {
		printf("Extraneous text after end of command\n\n");
		return 0;
	}

	if (!is_number(imaginary_input)) {
		printf("Invalid parameter - not a number\n\n");
		return 0;
	}

	read_comp(complex_array[variable - 'A'], (double)atof(real_input), (double)atof(imaginary_input));
	
	return 1;
}


int check_and_execute_print_comp(command_line* user_command_line, complex* complex_array[]) {
	char* variable_string;
	char variable;
	int full_line_size;
	int last_index;

	if ((variable_string = get_string(user_command_line, '\n')) == 0) {
		printf("Missing parameter\n\n");
		return 0;
	}

	variable = variable_string[0];
    full_line_size = strlen(user_command_line->full_line);
	last_index = full_line_size - 1;

	if (!variable_valid(variable)) {
		printf("Undefined complex variable\n\n");
		return 0;
	}

	if (strchr(variable_string, ' ') || (user_command_line->full_line[last_index]) == ',') {
		printf("Extraneous text after end of command\n\n");
		return 0;
	}

	if (strlen(variable_string) > 1) {
		printf("Undefined complex variable\n\n");
		return 0;
	}

	print_comp(*complex_array[variable - 'A']);

	return 1;
}


int check_and_execute_add_comp(command_line* user_command_line, complex* complex_array[]) {
	char variable1;
	char variable2;
	char* variable1_string;
	char* variable2_string;
	int full_line_size;
	int last_index;
	complex sum_result;

	if ((variable1_string = get_string(user_command_line, ',')) == 0) {
		printf("Missing parameter\n\n");
		return 0;
	}

	if ((variable2_string = get_string(user_command_line, '\n')) == 0) {
		printf("Missing parameter\n\n");
		return 0;
	}

	variable1 = variable1_string[0];
	variable2 = variable2_string[0];
	full_line_size = strlen(user_command_line->full_line);
	last_index = full_line_size - 1;

	/* Check variable 1 */
	if (!variable_valid(variable1) || strlen(variable1_string) > 1) {
		printf("Undefined complex variable\n\n");
		return 0;
	}

	/* Check variable 2 */
	if (!variable_valid(variable2)) {
		printf("Undefined complex variable\n\n");
		return 0;
	}

	if (strchr(variable2_string, ' ') || (user_command_line->full_line[last_index]) == ',') {
		printf("Extraneous text after end of command\n\n");
		return 0;
	}

	if (strlen(variable2_string) > 1) {
		printf("Undefined complex variable\n\n");
		return 0;
	}

	sum_result = add_comp(*complex_array[variable1 - 'A'], *complex_array[variable2 - 'A']);
	print_comp(sum_result);

	return 1;
}


int check_and_execute_sub_comp(command_line* user_command_line, complex* complex_array[]) {
	int full_line_size;
	int last_index;
	char variable1;
	char variable2;
	char* variable1_string;
	char* variable2_string;
	complex sub_result;

	if ((variable1_string = get_string(user_command_line, ',')) == 0) {
		printf("Missing parameter\n\n");
		return 0;
	}

	if ((variable2_string = get_string(user_command_line, '\n')) == 0) {
		printf("Missing parameter\n\n");
		return 0;
	}

	variable1 = variable1_string[0];
	variable2 = variable2_string[0];

	full_line_size = strlen(user_command_line->full_line);
	last_index = full_line_size - 1;

	/* Check variable 1 */
	if (!variable_valid(variable1) || strlen(variable1_string) > 1) {
		printf("Undefined complex variable\n\n");
		return 0;
	}

	/* Check variable 2 */
	if (!variable_valid(variable2)) {
		printf("Undefined complex variable\n\n");
		return 0;
	}

	if (strchr(variable2_string, ' ') || (user_command_line->full_line[last_index]) == ',') {
		printf("Extraneous text after end of command\n\n");
		return 0;
	}

	if (strlen(variable2_string) > 1) {
		printf("Undefined complex variable\n\n");
		return 0;
	}

	sub_result = sub_comp(*complex_array[variable1 - 'A'], *complex_array[variable2 - 'A']);
	print_comp(sub_result);

	return 1;
}


int check_and_execute_mult_comp_real(command_line* user_command_line, complex* complex_array[]) {
	int full_line_size;
	int last_index;
	char* variable_string;
	char variable;
	char* real_input;
	complex mult_result;

	if ((variable_string = get_string(user_command_line, ',')) == 0) {
		printf("Missing parameter\n\n");
		return 0;
	}

	variable = variable_string[0];
	full_line_size = strlen(user_command_line->full_line);
	last_index = full_line_size - 1;

	/* Check variable */
	if (!variable_valid(variable) || strlen(variable_string) > 1) {
		printf("Undefined complex variable\n\n");
		return 0;
	}

	/* Check number */
	if ((real_input = get_string(user_command_line, '\n')) == 0) {
		printf("Missing parameter\n\n");
		return 0;
	}

	if (strchr(real_input, ' ') || (user_command_line->full_line[last_index]) == ',') {
		printf("Extraneous text after end of command\n\n");
		return 0;
	}

	if (!is_number(real_input)) {
		printf("Invalid parameter - not a number\n\n");
		return 0;
	}

	mult_result = mult_comp_real(*complex_array[variable - 'A'], atof(real_input));
	print_comp(mult_result);

	return 1;
}


int check_and_execute_mult_comp_img(command_line* user_command_line, complex* complex_array[]) {
	int full_line_size;
	int last_index;
	char* variable_string;
	char variable;
	char* imginary_input;
	complex mult_result;

	if ((variable_string = get_string(user_command_line, ',')) == 0) {
		printf("Missing parameter\n\n");
		return 0;
	}

	variable = variable_string[0];
	
	full_line_size = strlen(user_command_line->full_line);
	last_index = full_line_size - 1;

	/* Check variable */
	if (!variable_valid(variable) || strlen(variable_string) > 1) {
		printf("Undefined complex variable\n\n");
		return 0;
	}

	/* Check number */
	if ((imginary_input = get_string(user_command_line, '\n')) == 0) {
		printf("Missing parameter\n\n");
		return 0;
	}

	if (strchr(imginary_input, ' ') || (user_command_line->full_line[last_index]) == ',') {
		printf("Extraneous text after end of command\n\n");
		return 0;
	}

	if (!is_number(imginary_input)) {
		printf("Invalid parameter - not a number\n\n");
		return 0;
	}

	mult_result = mult_comp_img(*complex_array[variable - 'A'], atof(imginary_input));
	print_comp(mult_result);
	
	return 1;
}


int check_and_execute_mult_comp_comp(command_line* user_command_line, complex* complex_array[]) {
	char variable1;
	char variable2;
	char* variable1_string;
	char* variable2_string;
	int full_line_size;
	int last_index;
	complex mult_result;

	if ((variable1_string = get_string(user_command_line, ',')) == 0) {
		printf("Missing parameter\n\n");
		return 0;
	}

	if ((variable2_string = get_string(user_command_line, '\n')) == 0) {
		printf("Missing parameter\n\n");
		return 0;
	}

	variable1 = variable1_string[0];
	variable2 = variable2_string[0];

	full_line_size = strlen(user_command_line->full_line);
	last_index = full_line_size - 1;

	/* Check variable 1 */
	if (!variable_valid(variable1) || strlen(variable1_string) > 1) {
		printf("Undefined complex variable\n\n");
		return 0;
	}

	/* Check variable 2 */
	if (!variable_valid(variable2)) {
		printf("Undefined complex variable\n\n");
		return 0;
	}

	if (strchr(variable2_string, ' ') || (user_command_line->full_line[last_index]) == ',') {
		printf("Extraneous text after end of command\n\n");
		return 0;
	}

	if (strlen(variable2_string) > 1) {
		printf("Undefined complex variable\n\n");
		return 0;
	}

	mult_result = mult_comp_comp(*complex_array[variable1 - 'A'], *complex_array[variable2 - 'A']);
	print_comp(mult_result);
	
	return 1;
}


int check_and_execute_abs_comp(command_line* user_command_line, complex* complex_array[]) {
	double abs_result;
	char* variable_string;
	char variable;
	int full_line_size;
	int last_index;

	if ((variable_string = get_string(user_command_line, '\n')) == 0) {
		printf("Missing parameter\n\n");
		return 0;
	}

	variable = variable_string[0];
	full_line_size = strlen(user_command_line->full_line);
	last_index = full_line_size - 1;

	if (!variable_valid(variable)) {
		printf("Undefined complex variable\n\n");
		return 0;
	}

	if (strchr(variable_string, ' ') || (user_command_line->full_line[last_index]) == ',') {
		printf("Extraneous text after end of command\n\n");
		return 0;
	}

	if (strlen(variable_string) > 1) {
		printf("Undefined complex variable\n\n");
		return 0;
	}

	abs_result = abs_comp(*complex_array[variable - 'A']);
	printf("%.2f\n", abs_result);

	return 1;
}

int check_stop(command_line* user_command_line) {
	int i;
	char* ending_characters = get_string(user_command_line, '\n');

	for (i = 0; i < strlen(ending_characters); i++) {
		if (!isblank(ending_characters[i])) {
			printf("Extraneous text after end of command\n\n");
			return 0;
		}
	}

	return 1;
}