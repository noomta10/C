/* Compare two files */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

FILE* my_open(char* name, char* mode) {
	FILE* fp;
	char msg[30];
	fp = fopen(name, mode);
	if (fp == NULL) {
		sprintf(msg, "%s", name);
		perror(msg);
		exit(1);
	}
	return (fp);
}


main(int argc, char* argv[]) {
	FILE* file1;
	FILE* file2;
	int line;
	char buf1[100], buf2[100];

	if (argc != 3) {
		fprintf(stderr, "Usage: %s file file\n", argv[0]);
		exit(2);
	}

	file1 = my_open(argv[1], "r");
	file2 = my_open(argv[2], "r");
	line = 1;
	
	char* line_file1 = fgets(buf1, sizeof(buf1), file1);
	char* line_file2 = fgets(buf2, sizeof(buf2), file2);

	while (1) {

		if (strcmp(buf1, buf2) != 0) {
			printf("files differ: line %d\n%s: %s\n%s: %s",line, argv[1], buf1, argv[2], buf2);
			exit(3);
		}

		char* line_file1 = fgets(buf1, sizeof(buf1), file1);
		char* line_file2 = fgets(buf2, sizeof(buf2), file2);

		line++;
	}


	fclose(file1);
	fclose(file2);
}