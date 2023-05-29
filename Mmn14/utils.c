#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "assembler.h"

char* add_file_postfix(char* file_name, char* postfix) {
	char* full_file_name = (char*)malloc_with_check(strlen(file_name) + strlen(postfix) + 1);
	strcpy(full_file_name, file_name);
	strcat(full_file_name, postfix);
	return full_file_name;
}


void* malloc_with_check(long length) {
	void* pointer = malloc(length);
	if (pointer == NULL) {
		printf("Error: memory allocation failed\n");
		exit(-1);
	}
	return pointer;
}


char* get_next_element(char* line) {
	int start_word_index;
	int end_word_index;
	int word_length;
	int i = 0;
	char element[MAX_LINE_LENGTH];
	
	/* Skip spaces and tabs */
	while (line + i == ' ' || line + i == '\t') {
		i++;
	}

	start_word_index = i;

	while ((line + i) != ' ' && (line + i) != '\t') {
		i++;
	}

	end_word_index = i;
	word_length = end_word_index - start_word_index + 1;
	char* word = malloc(word_length + 1);
	strncpy(word, start_word_index, word_length);
	word[word_length - 1] = '\0';

	return word;
}