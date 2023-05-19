#include <math.h> /* Provides mathematical functions */
#include <stdio.h>  /* Provides input and output functions */


/* Complex struct has 2 memebers:
1. real- a double, represents the real part of a complex number.
2. imaginary- a double, represents the imaginary part of a complex number. */
typedef struct {
	double real;
	double imaginary;
} complex;

/* Complex */ 

/* Read_comp function gets a pointer to a complex variable, a double real number and a double imaginary number.
It puts the real and the double part in their respective addresss in the complex variable pointer. */
void read_comp(complex* variable, double real, double imaginary);

/* Print_comp function gets a complex variable, and print its real and imaginary members in a formatted way. */
void print_comp(complex variable);

/* Add_comp function gets 2 complex variables and add the real part and the imaginary part of each of them.
Returns a complex number of the sum result */
complex add_comp(complex first_variable, complex second_variable);

/* Sud_comp function gets 2 complex variables and subtract the real part and the imaginary part of each of them.
Returns a complex number of the difference result */
complex sub_comp(complex first_variable, complex second_variable);

/* Mult_comp_real function gets a complex variable and a double real number, and multiple each member with the real number.
Returns a complex number of the product result */
complex mult_comp_real(complex variable, double real_number);

/* Mult_comp_img function gets a complex variable and a double imaginary number, and multiple each member with the imaginary number.
Returns a complex number of the product result */
complex mult_comp_img(complex variable, double imaginary_number);

/* Mult_comp_comp function gets 2 complex variable and calculate their product.
Returns a complex number of the product result */
complex mult_comp_comp(complex first_variable, complex second_variable);

/* Abs_comp function gets a complex variable and calculates its absolute value.
Returns a double number of the absolute result */
double abs_comp(complex variable);
