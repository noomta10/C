#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <stdlib.h>
#include "Mmn12-copy.h"
								
struct dynamic_array {
	int size;
	int* array_pointer;
};


int main(void) {
	struct dynamic_array set;
	set = get_set();
	print_set(set);

}


struct dynamic_array get_set() {
	struct dynamic_array set = {INITIAL_ARRAY_SIZE, NULL};
	struct dynamic_array full_array = {INITIAL_ARRAY_SIZE, NULL};
	int number;

	printf("Enter numbers:\n");

	while (scanf("%d", &number) == INT_FOUND) {
		add_number_to_array(&full_array, number);

		if (!number_in_array(set, number)) {
			add_number_to_array(&set, number);
		}
	}

	print_full_array(full_array);
	return set;
}


void add_number_to_array(struct dynamic_array* my_array, int number) {
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


int number_in_array(struct dynamic_array my_array, int number) {
	int index;

	for (index = 0; index < my_array.size; index++) {
		if (*(my_array.array_pointer + index) == number)
			return TRUE;
	}

	return FALSE;
}


void print_set(struct dynamic_array set) {
	int index;
	printf("Set is:\n");

	for (index = 0; index < set.size; index++)
		printf("%d ", *(set.array_pointer + index));

	printf("\n");
}


void print_full_array(struct dynamic_array full_array) {
	int index;
	printf("Full array received is:\n");

	for (index = 0; index < full_array.size; index++)
		printf("%d ", *(full_array.array_pointer + index));

	printf("\n");
}
