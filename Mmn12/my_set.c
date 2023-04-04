#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <stdlib.h>
#define ENLARGE_SIZE sizeof(int)
#define NUMBER_EXISTS 1
#define NUMBER_DOESNT_EXIST 0
#define NUMBER_OF_ELEMENTS 0
#define NO_ERRORS
#define ERROR 1
#define INT_FOUND 1 


int* get_set(void);
void print_set(int* set_pointer, int number_of_elements);
int number_in_array(int number, int *array_pointer, int number_of_elements);

int main(void) {
	int* set_pointer = get_set();
	print_set(set_pointer, set_pointer[NUMBER_OF_ELEMENTS]);
	free(set_pointer);

	return NO_ERRORS;
}

// create a set
int* get_set(void) {
	int number; // users number
	int index = 1; // index of number in the array
	int size = 1; // initial size of array
	int* array_pointer = (int*) malloc(size); // allocate memory for the array

	if (array_pointer == NULL) {
		printf("Error: memory allocation failed\n");
		exit(ERROR);
	}

	printf("Enter numbers:\n");
	while (scanf("%d", &number) == INT_FOUND) {
		printf("%d ", number);

		if(!number_in_array(number, array_pointer, size)) {
			size++;
			array_pointer = realloc(array_pointer, size * ENLARGE_SIZE);

			if (array_pointer == NULL) {
				printf("Error: memory reallocation failed\n");
				exit(ERROR);
			}
		
			*(array_pointer + index++) = number;
		}
	}

	array_pointer[NUMBER_OF_ELEMENTS] = --index;
	return array_pointer;
}

// print a set
void print_set(int *set_pointer, int number_of_elements) {
	for (int index = 1; index <= number_of_elements; index++) {
		printf("%d ", *(set_pointer + index));
	}
}

// check if number is present in the array
int number_in_array(int number, int* array_pointer, int number_of_elements)
{
	for (int i = 0; i < number_of_elements; i++) {
		if (array_pointer[i] == number)
			return NUMBER_EXISTS;
	}

	return NUMBER_DOESNT_EXIST;
}
