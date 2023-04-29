#define _CRT_SECURE_NO_WARNINGS 


#include "complex.h"

void variable_valid(char variable) {
	int index;
	int valid_variable = 0;
	char valid_variables[6] = { 'A', 'B', 'C', 'D', 'E', 'F' };

	for (index = 0; index < 6; index++) {
		if (variable == valid_variables[index])
			valid_variable = 1;
	}

	return valid_variable;
}

void check_read_comp_syntax(char* line, complex complex_array[]) {
	int line_index = 0;
	char variable;
	double first_number = 0;
	double second_number = 0;

	/* Skip blanks and tabs */
	while (line[line_index] == ' ' || line[line_index] == '\t')
		line_index++;

	/* Check variable validity */
	variable = line[line_index];
	if (!variable_valid)
		printf("Undefined complex variable");
	line_index++;

	if (line[line_index] != ' ' && line[line_index] != '\t' && line[line_index] != ',') {
		printf("Undefined complex variable");
	}
	
	/* Skip blanks and tabs */
	while (line[line_index] == ' ' || line[line_index] == '\t')
		line_index++;

	if (line[line_index] != ',') {
		printf("Missing comma");
	}
	line_index++;

	/* Skip blanks and tabs */
	while (line[line_index] == ' ' || line[line_index] == '\t')
		line_index++;

	line += line_index;
	scanf("%lf %lf", first_number, second_number);

	read_comp(complex_array[0], first_number, second_number);

}
