#include "complex.h"


/* Main function defines 6 complex variables and puts their addresses in an array.
Then, it gets a line from the user with the function get_line, as long as the line is not "stop". 
In the loop it checks if the users' line is EOF, if it is, it prints an error message and break the loop.
If command ends with EOF, it trims and excecutes it.
Then, it sends the command, the pointer to the user_command_line, and the complex_array to handle_command function. 
Finally, it frees the memory space and return NO_ERRORS */
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
	return NO_ERRORS;
}


/* Handle_command function gets a pointer to the command, a struct to the user cimmand line (contains the full line pointer and an int number of parse index), 
and an array of pointers to structs from type complex.
First, it checks if the command name is NULL, if it is, it prints an error message and exit.
Then, it calls check_consecutive_commas function, if there are multiple consecutive commas, it prints an error message and exit.
After that it checks what the received command is, then refers to the appropriate function that handles that command.
Finally, if the command did not match to any of the valid commands, it prints an appropriate error message and exit. */
void handle_command(char* command, command_line* user_command_line, complex* complex_array[]) {
	if (command == NULL) {
		printf("Missing command name\n\n");
		return;
	}
	if (check_consecutive_commas(user_command_line->full_line)) {
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
		if (check_command_comma(command)) {
			printf("Illegal comma\n\n");
			return;
		}

		printf("Undefined command name\n\n");
		return;
	}
}


/* Check_and_execute_read_comp function gets a pointer to a struct of the user command line (contains the full line received, and an int number of parse index),
and an array of pointers to structs from complex type.
It uses the get_string function to parse the full row string to get the desired parameter whenever it needs one.
If it fails to get the desired parameter, it prints an appropriate error message, frees the allocated memory space, and exits the function.
Otherwise, it calls the read_comp function with the necessary parameters. */
void check_and_execute_read_comp(command_line* user_command_line, complex* complex_array[]) {
	int full_line_size;
	int last_index;
	char* real_input;
	char* imaginary_input;
	char variable;
	char* variable_string;

	if ((variable_string = get_string(user_command_line, ',')) == 0) {
		printf("Missing parameter\n\n");
		return;
	}

	variable = variable_string[0];
	full_line_size = strlen(user_command_line->full_line);
	last_index = full_line_size - 1;

	if (!check_missing_comma(user_command_line->full_line, 2)) {
		printf("Missing comma\n\n");
		free(variable_string);
		return;
	}

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


/* Check_and_execute_print_comp function gets a pointer to a struct of the user command line (contains the full line received, and an int number of parse index),
and an array of pointers to structs from complex type.
It uses the get_string function to parse the full row string to get the variable name.
If it fails to get it, it prints an appropriate error message, frees the allocated memory space, and exits the function.
Otherwise, it calls the print_comp function with the defined variable. */
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


/* Check_and_execute_add_comp function gets a pointer to a struct of the user command line (contains the full line received, and an int number of parse index),
and an array of pointers to structs from complex type.
It uses the get_string function to parse the full row string to get the variables name.
If it fails to get them, it prints an appropriate error message, frees the allocated memory space, and exits the function.
Otherwise, it calls the add_comp function with the defined variables and prints the sum result. */
void check_and_execute_add_comp(command_line* user_command_line, complex* complex_array[]) {
	char variable1;
	char variable2;
	char* variable1_string;
	char* variable2_string;
	int full_line_size;
	int last_index;
	complex sum_result;

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


/* Check_and_execute_sub_comp function gets a pointer to a struct of the user command line (contains the full line received, and an int number of parse index),
and an array of pointers to structs from complex type.
It uses the get_string function to parse the full row string to get the variables name.
If it fails to get them, it prints an appropriate error message, frees the allocated memory space, and exits the function.
Otherwise, it calls the sub_comp function with the defined variables and prints the subtraction result. */
void check_and_execute_sub_comp(command_line* user_command_line, complex* complex_array[]) {
	int full_line_size;
	int last_index;
	char variable1;
	char variable2;
	char* variable1_string;
	char* variable2_string;
	complex sub_result;

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


/* Check_and_execute_mult_comp_real function gets a pointer to a struct of the user command line (contains the full line received, and an int number of parse index),
and an array of pointers to structs from complex type.
It uses the get_string function to parse the full row string to get the variable name and the real number.
If it fails to get them, it prints an appropriate error message, frees the allocated memory space, and exits the function.
Otherwise, it calls the mult_comp_real function with the necessary parameters and prints the multiplication result. */
void check_and_execute_mult_comp_real(command_line* user_command_line, complex* complex_array[]) {
	int full_line_size;
	int last_index;
	char* variable_string;
	char variable;
	char* real_input;
	complex mult_result;

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


/* Check_and_execute_mult_comp_img function gets a pointer to a struct of the user command line (contains the full line received, and an int number of parse index),
and an array of pointers to structs from complex type.
It uses the get_string function to parse the full row string to get the variable name and the imaginary number.
If it fails to get them, it prints an appropriate error message, frees the allocated memory space, and exits the function.
Otherwise, it calls the mult_comp_img function with the necessary parameters and prints the multiplication result. */
void check_and_execute_mult_comp_img(command_line* user_command_line, complex* complex_array[]) {
	int full_line_size;
	int last_index;
	char* variable_string;
	char variable;
	char* imaginary_input;
	complex mult_result;

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


/* Check_and_execute_mult_comp_comp function gets a pointer to a struct of the user command line (contains the full line received, and an int number of parse index),
and an array of pointers to structs from complex type.
It uses the get_string function to parse the full row string to get the variables name.
If it fails to get them, it prints an appropriate error message, frees the allocated memory space, and exits the function.
Otherwise, it calls the mult_comp_comp function with the variables and prints the multiplication result. */
void check_and_execute_mult_comp_comp(command_line* user_command_line, complex* complex_array[]) {
	char variable1;
	char variable2;
	char* variable1_string;
	char* variable2_string;
	int full_line_size;
	int last_index;
	complex mult_result;

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


/* Check_and_execute_abs_comp function gets a pointer to a struct of the user command line (contains the full line received, and an int number of parse index),
and an array of pointers to structs from complex type.
It uses the get_string function to parse the full row string to get the variable name.
If it fails to get it, it prints an appropriate error message, frees the allocated memory space, and exits the function.
Otherwise, it calls the abs_comp function with the variable and prints the absolute result. */
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


/* Check_stop function gets a command_line pointer to the user command line. 
It checks if the characters after the command are spaces or tabs.
If they are not, prints an appropriate error message, frees the allocated memory space, and returns FALSE. 
Else, it frees the allocated memory space returns TRUE. */
int check_stop(command_line* user_command_line) {
	char* ending_characters = get_string(user_command_line, '\n');

	if (ending_characters){
		printf("Extraneous text after end of command\n\n");
		free(ending_characters);
		return FALSE;
	}

	free(ending_characters);
	return TRUE;
}
