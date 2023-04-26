#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char line[100] = "read_comp A, 1, 2";
	char command[10];
	char variable_name;
	double real;
	double imaginary;

	sscanf(line, "%s  %c, %lf, %lf", command, &variable_name, &real, &imaginary);
	printf("%s\n%c\n%f\n%f\n", command, variable_name, real, imaginary);
}