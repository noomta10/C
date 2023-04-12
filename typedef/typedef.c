#include <stdio.h>
#include <stdlib.h>

/* Complex number */
typedef struct {
	double real;
	double imaginary;
} Complex;


/* Add 2 complex numbers return a Complex variable */
Complex add_complex(Complex* number1, Complex* number2) {
	Complex result;
	result.real = number1->real + number2->real;
	result.imaginary = number1->imaginary + number2->imaginary;
	return result;
}

/* Add 2 complex numbers return a Complex pointer */
Complex* add_complex2(Complex* number1, Complex* number2) {
	Complex* result_pointer = malloc(sizeof(Complex));

	if (result_pointer == NULL) {
		printf("Error allocation memory\n");
		exit(1);
	}

	result_pointer->real = number1->real + number2->real;
	result_pointer->imaginary = number1->imaginary + number2->imaginary;
	return result_pointer;
}

/* Check the above functions */
int main() {
	Complex number1 = { 5, 1 };
	Complex number2 = { 5, 2 };
	Complex result = add_complex(&number1, &number2);
	printf("%.2f, +%.2fi\n", result.real, result.imaginary);

	Complex* result2 = add_complex2(&number1, &number2);
	printf("%.2f, +%.2fi", result2->real, result2->imaginary);

	return 0;
}
