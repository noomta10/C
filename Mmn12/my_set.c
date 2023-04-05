#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h> 
#include <stdlib.h>
#include "my_set.h"

int main(void) {
	int* set_pointer = get_set();
	print_set(set_pointer, set_pointer[NUMBER_OF_ELEMENTS_INDEX]);
	free(set_pointer);

	return NO_ERRORS;
}


// Create a set
int* get_set(void) {
	int number; // Users number
	int set_index = FIRST_INDEX; // Index of number in set
	int set_size = INITIAL_ARRAY_SIZE; // Initial size of set
	int* set_pointer = (int*)malloc(set_size); // Allocate memory for the set pointer
	int full_array_index = FIRST_INDEX; // Index of number in full array
	int full_array_size = INITIAL_ARRAY_SIZE; // Initial size of full array
	int* full_array_pointer = (int*)malloc(full_array_size); // Allocate memory for the full array pointer 

	if (set_pointer == NULL || full_array_pointer == NULL) {
		printf("Error: memory allocation failed\n");
		exit(MEMORY_ERROR);
	}

	printf("Enter numbers:\n");
	while (scanf("%d", &number) == INT_FOUND) {
		add_number_to_array(&full_array_pointer, number, &full_array_size, &full_array_index);

		if (!number_in_array(number, set_pointer, set_size)) {
			add_number_to_array(&set_pointer, number, &set_size, &set_index);
		}
	}

	int full_array_number_of_elements = --full_array_index;
	full_array_pointer[NUMBER_OF_ELEMENTS_INDEX] = full_array_number_of_elements;
	print_input(full_array_pointer, full_array_number_of_elements);

	set_pointer[NUMBER_OF_ELEMENTS_INDEX] = --set_index;
	return set_pointer;
}


// Print a set
void print_set(int* set_pointer, int number_of_elements) {
	int index = FIRST_INDEX;
	printf("Set is:\n");

	for (index; index <= number_of_elements; index++)
		printf("%d ", *(set_pointer + index));

	printf("\n");
}


// Add number to the array
void add_number_to_array(int** pointer_to_pointer, int number, int* size_pointer, int* index_pointer) {
	(*size_pointer)++;
	*pointer_to_pointer = realloc(*pointer_to_pointer, *size_pointer * ENLARGE_SIZE);

	if (*pointer_to_pointer == NULL) {
		printf("Error: memory reallocation failed\n");
		exit(MEMORY_ERROR);
	}

	*(*pointer_to_pointer + *index_pointer) = number;
	(*index_pointer)++;
}


// Check if number is present in the array
int number_in_array(int number, int* array_pointer, int number_of_elements)
{
	int index = FIRST_INDEX;

	for (index; index < number_of_elements; index++) {
		if (array_pointer[index] == number)
			return NUMBER_EXISTS;
	}

	return NUMBER_DOESNT_EXIST;
}


// Print all the numbers the user entered 
void print_input(int* full_array_pointer, int number_of_elements) {
	int index = FIRST_INDEX;
	printf("Numbers received are:\n");

	for (index; index <= number_of_elements; index++)
		printf("%d ", *(full_array_pointer + index));

	printf("\n");
}
