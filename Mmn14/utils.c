#define _CRT_SECURE_NO_WARNINGS
#include "utils.h"

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