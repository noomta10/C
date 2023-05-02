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
	complex* complex_array[6] = {&A, &B, &C, &D, &E, &F};

	printf("Enter a command:\n");
	user_command_line.full_line = get_line(line);

	while (strcmp(user_command_line.full_line, "stop") != 0) {
		printf("Line received is: %s\n", user_command_line.full_line);
		command = get_string(&user_command_line, ' ');
		handle_command(command, &user_command_line, complex_array);
		printf("Enter a command:\n");
		user_command_line.full_line = get_line(user_command_line.full_line);
		user_command_line.parse_index = 0;
	}
}


void handle_command(char* command, command_line* user_command_line, complex* complex_array[]) {
	if (strcmp(command, "read_comp") == 0) {
		check_and_execute_read_comp(user_command_line, complex_array);
	}
	else if (strcmp(command, "print_comp") == 0) {
		check_and_execute_print_comp(user_command_line, complex_array);
	}
	else if (strcmp(command, "add_comp") == 0) {
		check_and_execute_add_comp(user_command_line, complex_array);
	}
	else if (strcmp(command, "sub_comp") == 0) {
		check_and_execute_sub_comp(user_command_line, complex_array);
	}
	else if (strcmp(command, "mult_comp_real") == 0) {
		check_and_execute_mult_comp_real(user_command_line, complex_array);
	}
	else if (strcmp(command, "mult_comp_img") == 0) {
		check_and_execute_mult_comp_img(user_command_line, complex_array);
	}
	else if (strcmp(command, "mult_comp_comp") == 0) {
		check_and_execute_mult_comp_comp(user_command_line, complex_array);
	}
	else if (strcmp(command, "abs_comp") == 0) {
		check_and_execute_abs_comp(user_command_line, complex_array);
	}
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