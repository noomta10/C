#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <stdlib.h>
#define ENLARGE_SIZE sizeof(int)
#define NUMBER_EXISTS 1
#define NUMBER_DOESNT_EXIST 0
#define NUMBER_OF_ELEMENTS_INDEX 0
#define NO_ERRORS 0
#define MEMORY_ERROR 1
#define INT_FOUND 1 
#define INITIAL_ARRAY_SIZE 1
#define FIRST_INDEX 1
#define FIRST_ITERATION 1
#define NOT_FIRST_ITERATION 0



int* get_set(void);
void print_set(int* set_pointer, int number_of_elements);
int number_in_array(int number, int *array_pointer, int number_of_elements);

int main(void) {
	int* set_pointer = get_set();
	print_set(set_pointer, set_pointer[NUMBER_OF_ELEMENTS_INDEX]);
	free(set_pointer);

	return NO_ERRORS;
}

// create a set
int* get_set(void) {
	int number; // users number
	int index = FIRST_INDEX; // index of number in the array
	int size = INITIAL_ARRAY_SIZE; // initial size of array
	int* array_pointer = (int*) malloc(size); // allocate memory for the array
	int first_iteration = FIRST_ITERATION; // first iteration in while loop to print a title

	if (array_pointer == NULL) {
		printf("Error: memory allocation failed\n");
		exit(MEMORY_ERROR);
	}

	printf("Enter numbers:\n");
	while (scanf("%d", &number) == INT_FOUND) {
		if (first_iteration) {
			printf("Numbers are:\n");
			first_iteration = NOT_FIRST_ITERATION;
		}
		printf("%d ", number);

		if(!number_in_array(number, array_pointer, size)) {
			size++;
			array_pointer = realloc(array_pointer, size * ENLARGE_SIZE);

			if (array_pointer == NULL) {
				printf("Error: memory reallocation failed\n");
				exit(MEMORY_ERROR);
			}
		
			*(array_pointer + index++) = number;
		}
	}

	array_pointer[NUMBER_OF_ELEMENTS_INDEX] = --index;
	return array_pointer;
}

// print a set
void print_set(int *set_pointer, int number_of_elements) {
	printf("\nSet is:\n");
	for(int index = 1; index <= number_of_elements; index++) {
		printf("%d ", *(set_pointer + index));
	}
	printf("\n");
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
