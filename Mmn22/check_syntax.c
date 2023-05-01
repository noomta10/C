#include "complex.h"

int variable_valid(char variable) {
	int index;
	int valid_variable = 0;
	char valid_variables[6] = { 'A', 'B', 'C', 'D', 'E', 'F' };

	for (index = 0; index < 6; index++) {
		if (variable == valid_variables[index])
			valid_variable = 1;
	}

	return valid_variable;
}

void check_read_comp_syntax(command_line* user_command_line, complex* complex_array[]) {
	char* variable_string = get_string(user_command_line, ',');
	char variable_character = variable_string[0];
	double real_input;
	double imaginary_input;
	printf("%s\n", variable_string);

	if (strlen(variable_string) < 1)
		printf("Missing parameter\n");

	if (!variable_valid(variable_character))
		printf("Undefined complex variable\n");

	real_input = atof(get_string(user_command_line, ','));
	imaginary_input = atof(get_string(user_command_line, '\n'));

	printf("%lf\n", real_input);
	printf("%lf\n", imaginary_input);
	printf("Before change: %lf", complex_array[variable_character]->imaginary);

	read_comp(complex_array[variable_character], real_input, imaginary_input);

	
}
