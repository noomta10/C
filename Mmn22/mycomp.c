#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <string.h>
#include "complex.h"

complex A = { 0, 0 };
complex B = { 0, 0 };
complex C = { 0, 0 };
complex D = { 0, 0 };
complex E = { 0, 0 };
complex F = { 0, 0 };

char* check_command(char command[]) {
	char* command_name = strtok(command, " ");
	return command_name;
}

int main() {
	char command[100];
	printf("Enter a command:\n");
	scanf(" %[^\n]", command);

	while (strcmp(command, "stop") != 0) {
		printf("%s\n", command);
		printf("%s\n", check_command(command));
		printf("Enter a command:\n");
		scanf("%[^\n]", command);
	}
}

