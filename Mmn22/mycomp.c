#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "complex.h"

#define ENLARGE_SIZE(size) ++size 
#define CHAR_SIZE sizeof(char)


void check_line(char* line) {
	int i = 0;
	int command_size = 0;
	char* command = (char*)malloc(ENLARGE_SIZE(command_size) * CHAR_SIZE);
	
	/* Skip blanks and tabs */
	while (line[i] == ' ' || line[i] == '\t')
		i++;

	/* Read command */
	while (line[i] != ' '){
		command[command_size-1] = line[i];
		command = (char*)realloc(command, ENLARGE_SIZE(command_size) * CHAR_SIZE);
		i++;
	}
	command[command_size-1] = '\0';
	printf("%s\n", command);
}


int main() {
	complex A = { 0, 0 };
	complex B = { 0, 0 };
	complex C = { 0, 0 };
	complex D = { 0, 0 };
	complex E = { 0, 0 };
	complex F = { 0, 0 };

	char line[100];


	printf("Enter a command:\n");
	scanf(" %[^\n]", line);

	while (strcmp(line, "stop") != 0) {
		printf("Line received is: %s\n", line);
		
		check_line(line);

		printf("Enter a command:\n");
		scanf(" %[^\n]", line);
	}
}

