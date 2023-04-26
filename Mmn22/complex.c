#include <stdio.h>
#include "complex.h"

void read_comp(complex *variable, double real, double imaginary) {
	variable->real = real;
	variable->imaginary = imaginary;
}

void print_comp(complex variable) {
	char sign;
	sign = variable.imaginary > 0 ? '+' : '-';
	printf("%.2lf %c %.2lfi\n", variable.real, sign, variable.imaginary);
}

complex add_comp(complex first_variable, complex second_variable) {
	complex sum;
	sum.real = first_variable.real + second_variable.real;
	sum.imaginary = first_variable.imaginary + second_variable.imaginary;
	return sum;
}

complex sub_comp(complex first_variable, complex second_variable) {
	complex difference;
	difference.real = first_variable.real - second_variable.real;
	difference.imaginary = first_variable.imaginary - second_variable.imaginary;
	return difference;
}

complex mult_comp_real(complex variable, double real_number) {
	complex product;
	product.real = variable.real * real_number;
	product.imaginary = variable.imaginary * real_number;
	return product;
}

complex mult_comp_img(complex variable, double imaginary_number) {
	complex product;

	return product;
}