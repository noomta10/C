#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h> 
#include <stdlib.h>
#include "Mmn12-structs.h"
								
/* Main function calls get_set function to create a set.
Then, it calls print_set function in order to print the set. 
Finally, it uses free function to deallocate the memory of the set pointer.
Returns 0 if the program was completed successfully */
int main() {
	dynamic_array set;
	set = get_set();
	print_set(set);
	free(set.array_pointer);
	return NO_ERRORS;
}

/* Get_set function gets input from the user until it reaches EOF, and creates 2 arrays:
1. Set- the purpose of the program, holds the set, where a number does not appear more than once.
2. Full array- holds the full array, where all the numbers the user entered appear.
The purpose of this array is for the input to be displayed nicely.
The function uses add_number_to_array function to add all of the numbers the user entered to the full array.
The function uses number_in_array function to check if number is present in the set,
if it is not, the function uses add_number_to_array function and adds the number to the set.
Finally, it calls print_full_array to print the full array to display the input as it was received,
and uses free function to deallocate the memory of the full array pointer.
Returns a dynamic_array. */
dynamic_array get_set() {
	dynamic_array set = {INITIAL_ARRAY_SIZE, NULL};
	dynamic_array full_array = {INITIAL_ARRAY_SIZE, NULL};
	int number;

	printf("Enter numbers:\n");

	while (scanf("%d", &number) == INT_FOUND) {
		add_number_to_array(&full_array, number);

		if (!number_in_array(set, number)) {
			add_number_to_array(&set, number);
		}
	}

	print_full_array(full_array);
	free(full_array.array_pointer);
	return set;
}

/*  Add_number_to_array function gets a pointer to a dynamic_array and the number the user entered.
If the size of the dynamic_array is 0, it uses malloc to allocate memory to the array.
Else, it uses realloc to reallocate more memory to the array.
Finally, it adds the number to the array. */
void add_number_to_array(dynamic_array* my_array, int number) {
	if (my_array->size == INITIAL_ARRAY_SIZE) {
		my_array->array_pointer = (int*)malloc(ENLARGE_SIZE(my_array->size) * INT_SIZE);
		
		if (my_array->array_pointer == NULL) {
			printf("Error: memory allocation failed\n");
			exit(MEMORY_ERROR);
		}
	}
	else {
		my_array->array_pointer = realloc(my_array->array_pointer, ENLARGE_SIZE(my_array->size) * INT_SIZE);
		
		if (my_array->array_pointer == NULL) {
			printf("Error: memory reallocation failed\n");
			exit(MEMORY_ERROR);
		}
	}

	*(my_array->array_pointer + (my_array->size - 1)) = number;
}

/* Number_in_array function gets a dynamic_array and the number the user enterd.
It loops through the array and checks if the number already exists in the array.
It returns an int. If the number exist, 1, else, it returns 0.*/
int number_in_array(dynamic_array my_array, int number) {
	int index;

	for (index = 0; index < my_array.size; index++) {
		if (*(my_array.array_pointer + index) == number)
			return TRUE;
	}

	return FALSE;
}

/* Print_set function gets a dynamic_array,
loops through the array and prints each number of the set until it reaches the size of the dynamic_array. */
void print_set(dynamic_array set) {
	int index;
	printf("Set is:\n");

	for (index = 0; index < set.size; index++)
		printf("%d ", *(set.array_pointer + index));

	printf("\n");
}

/* Print_full_arrau function gets a dynamic_array,
loops through the array and prints each number of the full array until it reaches the size of the dynamic_array. */
void print_full_array(dynamic_array full_array) {
	int index;
	printf("Full array received is:\n");

	for (index = 0; index < full_array.size; index++)
		printf("%d ", *(full_array.array_pointer + index));

	printf("\n");
}
