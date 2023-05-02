#include "complex.h"

char check_variable(char variable_string[]) {
	char variable_character;
	int index;
	int valid_variable = 0;
	char valid_variables[6] = { 'A', 'B', 'C', 'D', 'E', 'F' };

	if (strlen(variable_string) < 1)
		printf("Missing parameter\n");

	variable_character = variable_string[0];
;
	for (index = 0; index < 6; index++) {
		if (variable_character == valid_variables[index])
			valid_variable = 1;
	}

	if (!valid_variable) {
		printf("Undefined complex variable\n");
	}

	return variable_character;
}


void check_and_execute_read_comp(command_line* user_command_line, complex* complex_array[]) {
	double real_input;
	double imaginary_input;
	char* variable_string = get_string(user_command_line, ',');
	char variable = check_variable(variable_string);

	real_input = atof(get_string(user_command_line, ','));
	imaginary_input = atof(get_string(user_command_line, '\n'));

	read_comp(complex_array[variable - 'A'], real_input, imaginary_input);
}


void check_and_execute_print_comp(command_line* user_command_line, complex* complex_array[]) {
	char* variable_string = get_string(user_command_line, '\n');
	char variable = check_variable(variable_string);

	print_comp(*complex_array[variable - 'A']);
}


void check_and_execute_add_comp(command_line* user_command_line, complex* complex_array[]) {
	char* variable_string1 = get_string(user_command_line, ',');
	char variable1 = check_variable(variable_string1);
	char* variable_string2 = get_string(user_command_line, '\n');
	char variable2 = check_variable(variable_string2);

	complex sum_result = add_comp(*complex_array[variable1 - 'A'], *complex_array[variable2 - 'A']);
	print_comp(sum_result);
}


void check_and_execute_sub_comp(command_line* user_command_line, complex* complex_array[]) {
	char* variable_string1 = get_string(user_command_line, ',');
	char variable1 = check_variable(variable_string1);
	char* variable_string2 = get_string(user_command_line, '\n');
	char variable2 = check_variable(variable_string2);

	complex sub_result = sub_comp(*complex_array[variable1 - 'A'], *complex_array[variable2 - 'A']);
	print_comp(sub_result);
}


void check_and_execute_mult_comp_real(command_line* user_command_line, complex* complex_array[]) {
	char* variable_string = get_string(user_command_line, ',');
	char variable = check_variable(variable_string);
	double real_input = atof(get_string(user_command_line, '\n'));

	complex mult_result = mult_comp_real(*complex_array[variable - 'A'], real_input);
	print_comp(mult_result);
}


void check_and_execute_mult_comp_img(command_line* user_command_line, complex* complex_array[]) {
	char* variable_string = get_string(user_command_line, ',');
	char variable = check_variable(variable_string);
	double img_input = atof(get_string(user_command_line, '\n'));

	complex mult_result = mult_comp_img(*complex_array[variable - 'A'], img_input);
	print_comp(mult_result);
}


void check_and_execute_mult_comp_comp(command_line* user_command_line, complex* complex_array[]) {
	char* variable_string1 = get_string(user_command_line, ',');
	char variable1 = check_variable(variable_string1);
	char* variable_string2 = get_string(user_command_line, '\n');
	char variable2 = check_variable(variable_string2);

	complex mult_result = mult_comp_comp(*complex_array[variable1 - 'A'], *complex_array[variable2 - 'A']);
	print_comp(mult_result);
}

void check_and_execute_abs_comp(command_line* user_command_line, complex* complex_array[]) {
	char* variable_string = get_string(user_command_line, ',');
	char variable = check_variable(variable_string);
	double abs_result = abs_comp(*complex_array[variable - 'A']);

	printf("%.2lf\n", abs_result);
}
