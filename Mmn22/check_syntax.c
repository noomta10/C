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
	char* variable = get_string(user_command_line, ',');
	printf("%s\n", variable);
	if (!variable_valid(variable))
		printf("Undefined complex variable");

}
