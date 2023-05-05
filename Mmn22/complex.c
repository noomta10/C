#include "complex.h"

void read_comp(complex *variable, double real, double imaginary) {
	variable->real = real;
	variable->imaginary = imaginary;
}

void print_comp(complex variable) {
	char sign;
	sign = variable.imaginary > 0 ? '+' : '-';
	printf("%.2f %c %.2fi\n", variable.real, sign, fabs(variable.imaginary));
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
	complex real_product;
	real_product.real = variable.real * real_number;
	real_product.imaginary = variable.imaginary * real_number;
	return real_product;
}

complex mult_comp_img(complex variable, double imaginary_number) {
	complex imaginary_product;
	imaginary_product.real = -imaginary_number * variable.imaginary;
	imaginary_product.imaginary = imaginary_number * variable.real;
	return imaginary_product;
}

complex mult_comp_comp(complex first_variable, complex second_variable) {
	complex complex_product;
	complex_product.real = (first_variable.real * second_variable.real) - (first_variable.imaginary * second_variable.imaginary);
	complex_product.imaginary = (first_variable.real * second_variable.imaginary) + (first_variable.imaginary * second_variable.real);
	return complex_product;
}

double abs_comp(complex variable) {
	double abs_result;
	abs_result = sqrt(pow(variable.real, 2) + pow(variable.imaginary, 2));
	return abs_result;
}