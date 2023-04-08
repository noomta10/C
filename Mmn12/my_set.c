#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h> 
#include <stdlib.h>
#include "my_set.h"


/* Main function calls get_set function to create a set.
Then, it calls print_set function in order to print the set. 
Finally, it uses free function to deallocate the memory that was allocated to the set pointer.
Returns 0 if the program was completed successfully*/
int main(void) {
	int* set_pointer = get_set();
	print_set(set_pointer, set_pointer[NUMBER_OF_ELEMENTS_INDEX]);
	free(set_pointer);
	return NO_ERRORS;
}


/* Get_set function gets input from the user until it reaches EOF, and creates 2 arrays:
1. Set- the purpose of the program, holds the set, where a number does not appear more than once.
2. Full array- holds the full array, where all the numbers the user entered appear.
The purpose of this array is for the input to be displayed nicely
The function uses add_number_to_array function to add all of the numbers the user entered to the full array.
The function uses number_in_array function to check if number is present in the set,
if it is not, the function uses add_number_to_array function and adds the number to the set.
Then, the function puts in the first element of each array the number pf elements in the array,
which is the next free index (index variable) of the array minus 1.
Finally, it calls print_input to print the full array to display the input as it was received.
Returns a pointer to the set array */
int* get_set(void) {
	int number; /* Users number */
	int set_index = FIRST_INDEX; /* Index of number in set */
	int set_size = INITIAL_ARRAY_SIZE; /* Initial size of set */
	int* set_pointer = (int*)malloc(set_size*ENLARGE_SIZE); /* Allocate memory for the set pointer */
	int full_array_index = FIRST_INDEX; /* Index of number in full array */
	int full_array_size = INITIAL_ARRAY_SIZE; /* Initial size of full array  */
	int* full_array_pointer = (int*)malloc(full_array_size* ENLARGE_SIZE); /* Allocate memory for the full array pointer */

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
	free(full_array_pointer);
	set_pointer[NUMBER_OF_ELEMENTS_INDEX] = --set_index;
	return set_pointer;
}


/* Print_set function gets the pointer to the set and the number of elements in the set,
loops through the array, and prints each number of the set. */
void print_set(int* set_pointer, int number_of_elements) {
	int index = FIRST_INDEX;
	printf("Set is:\n");

	for (index; index <= number_of_elements; index++)
		printf("%d ", *(set_pointer + index));

	printf("\n");
}


/* Add_number_to_array function gets the pointer to the pointer (the set pointer or to the full array pointer),
the number the user entered, the pointer to the size of the array, and the the pointer to the index.
First it increases the size variable and reallocates memory to the new number,
then, it adds the number to the next free position in the array, and finally, increases the index variable. */
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


/* Number_in_array function gets the number the user enterd, the set pointer and number of elements in the set.
It loops through the array and checks if the number already exists in the array.
If the number exist, it returns 1, else, it returns 0.*/
int number_in_array(int number, int* set_pointer, int number_of_elements) {
	int index = FIRST_INDEX;

	for (index; index < number_of_elements; index++) {
		if (set_pointer[index] == number)
			return NUMBER_EXISTS;
	}

	return NUMBER_DOESNT_EXIST;
}

/* Print_input function gets the full array pointer and the number of elements in the array.
It loops through the array and prints all the numbers the user entered,
so the input will be displayed even when it comes from a file. */
void print_input(int* full_array_pointer, int number_of_elements) {
	int index = FIRST_INDEX;
	printf("Numbers received are:\n");

	for (index; index <= number_of_elements; index++)
		printf("%d ", *(full_array_pointer + index));

	printf("\n");
}
