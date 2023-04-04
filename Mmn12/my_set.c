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
int number_in_array(int number, int* array_pointer, int number_of_elements);
void add_number_to_array(int** pointer_to_pointer, int number, int size, int index);

int main(void) {
	int* set_pointer = get_set();
	print_set(set_pointer, set_pointer[NUMBER_OF_ELEMENTS_INDEX]);
	free(set_pointer);

	return NO_ERRORS;
}

// create a set
int* get_set(void) {
	int number; // users number
	int set_index = FIRST_INDEX; // index of number in the set
	int set_size = INITIAL_ARRAY_SIZE; // initial size of set
	int* set_pointer = (int*)malloc(set_size); // allocate memory for the set pointer
	int full_array_index = FIRST_INDEX; // index of number in the full array
	int full_array_size = INITIAL_ARRAY_SIZE; // initial size of full array
	int* full_array_pointer = (int*)malloc(full_array_size); // allocate memory for the full array pointer 

	if (set_pointer == NULL || full_array_pointer == NULL) {
		printf("Error: memory allocation failed\n");
		exit(MEMORY_ERROR);
	}

	printf("Enter numbers:\n");
	while (scanf("%d", &number) == INT_FOUND) {
		full_array_size++;
		add_number_to_array(&set_pointer, number, set_size, set_index);
		full_array_index++;

		if (!number_in_array(number, set_pointer, set_size)) {
			set_size++;
			add_number_to_array(&set_pointer, number, set_size, set_index);
			set_index++;
		}
	}

	full_array_pointer[NUMBER_OF_ELEMENTS_INDEX] = --full_array_index;
	printf("Numbers are:\n");
	for (int index = 1; index <= full_array_pointer[NUMBER_OF_ELEMENTS_INDEX]; index++) {
		printf("%d ", *(full_array_pointer + index));
	}

	set_pointer[NUMBER_OF_ELEMENTS_INDEX] = --set_index;
	return set_pointer;
}

// print a set
void print_set(int* set_pointer, int number_of_elements) {
	printf("\nSet is:\n");
	for (int index = 1; index <= number_of_elements; index++) {
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

void add_number_to_array(int** pointer_to_pointer, int number, int size, int index) {
	*pointer_to_pointer = realloc(*pointer_to_pointer, size * ENLARGE_SIZE);

	if (*pointer_to_pointer == NULL) {
		printf("Error: memory reallocation failed\n");
		exit(MEMORY_ERROR);
	}

	*(*pointer_to_pointer + index++) = number;
}
