#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

char* add_file_postfix(char* file_name, char* postfix) {
	char* full_file_name = (char*)malloc(strlen(file_name) + strlen(postfix) + 1);
	strcpy(full_file_name, file_name);
	strcat(full_file_name, postfix);
	return full_file_name;
}

int main() {
	FILE* my_file = fopen("my_file.txt", "w");
	fclose(my_file);
	if (rename("my_file.txt", "new_name.txt") != 0)
		printf("Error renaming file\n");


}
