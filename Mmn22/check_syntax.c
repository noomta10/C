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

void check_read_comp_syntax(command_line* user_command_line, complex* complex_array[]) {
	double real_input;
	double imaginary_input;
	char* variable_string = get_string(user_command_line, ',');
	char variable = check_variable(variable_string);

	real_input = atof(get_string(user_command_line, ','));
	imaginary_input = atof(get_string(user_command_line, '\n'));

	printf("%lf\n", real_input);
	printf("%lf\n", imaginary_input);
	read_comp(complex_array['A' - variable], real_input, imaginary_input);
}


void check_print_comp_syntax(command_line* user_command_line, complex* complex_array[]) {
	char* variable_string = get_string(user_command_line, '\n');
	char variable = check_variable(variable_string);

	print_comp(*complex_array['A' - variable]);
}

void check_add_comp_syntax(command_line* user_command_line, complex* complex_array[]) {
	char* variable_string1 = get_string(user_command_line, ',');
	char variable1 = check_variable(variable_string1);
	char* variable_string2 = get_string(user_command_line, '\n');
	char variable2 = check_variable(variable_string2);

	complex sum_result = add_comp(*complex_array['A' - variable1], *complex_array['A' - variable2]);
}