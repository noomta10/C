#include "complex.h"

/* Read_comp function gets a pointer to a complex variable, a double real number and a double imaginary number.
It puts the real and the double part in their respective addresss in the complex variable pointer. */
void read_comp(complex *variable, double real, double imaginary) {
	variable->real = real;
	variable->imaginary = imaginary;
}


/* Print_comp function gets a complex variable, and print its real and imaginary members in a formatted way. */
void print_comp(complex variable) {
	char sign;
	sign = variable.imaginary > 0 ? '+' : '-';
	printf("%.2f %c %.2fi\n", variable.real, sign, fabs(variable.imaginary));
}


/* Add_comp function gets 2 complex variables and add the real part and the imaginary part of each of them.
Returns a complex number of the sum result */
complex add_comp(complex first_variable, complex second_variable) {
	complex sum;
	sum.real = first_variable.real + second_variable.real;
	sum.imaginary = first_variable.imaginary + second_variable.imaginary;
	return sum;
}


/* Sud_comp function gets 2 complex variables and subtract the real part and the imaginary part of each of them.
Returns a complex number of the difference result */
complex sub_comp(complex first_variable, complex second_variable) {
	complex difference;
	difference.real = first_variable.real - second_variable.real;
	difference.imaginary = first_variable.imaginary - second_variable.imaginary;
	return difference;
}


/* Mult_comp_real function gets a complex variable and a double real number, and multiple each member with the real number.
Returns a complex number of the product result */
complex mult_comp_real(complex variable, double real_number) {
	complex real_product;
	real_product.real = variable.real * real_number;
	real_product.imaginary = variable.imaginary * real_number;
	return real_product;
}


/* Mult_comp_img function gets a complex variable and a double imaginary number, and multiple each member with the imaginary number.
Returns a complex number of the product result */
complex mult_comp_img(complex variable, double imaginary_number) {
	complex imaginary_product;
	imaginary_product.real = -imaginary_number * variable.imaginary;
	imaginary_product.imaginary = imaginary_number * variable.real;
	return imaginary_product;
}


/* Mult_comp_comp function gets 2 complex variable and calculate their product.
Returns a complex number of the product result */
complex mult_comp_comp(complex first_variable, complex second_variable) {
	complex complex_product;
	complex_product.real = (first_variable.real * second_variable.real) - (first_variable.imaginary * second_variable.imaginary);
	complex_product.imaginary = (first_variable.real * second_variable.imaginary) + (first_variable.imaginary * second_variable.real);
	return complex_product;
}


/* Abs_comp function gets a complex variable and calculates its absolute value.
Returns a double number of the absolute result */
double abs_comp(complex variable) {
	double abs_result;
	abs_result = sqrt(pow(variable.real, 2) + pow(variable.imaginary, 2));
	return abs_result;
}