#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>
#define ENLARGE_SIZE sizeof(int)

int* get_set(void);
void print_set(int* set_pointer, int number_of_elements);

int main(void) {
	int* set_pointer = get_set();
	print_set(set_pointer, set_pointer[0]);
	free(set_pointer);
	return 0;
}

// create a set
int* get_set(void) {
	int number; // users number
	int index = 1; // index of number in the array
	int size = 1; // number of elements in the array
	int* array_pointer = (int*) malloc(size); // allocate memory for the array

	if (array_pointer == NULL) {
		printf("Error: memory allocation failed\n");
		exit(1);
	}

	printf("Enter numbers:\n ");

	while (scanf("%d", &number) == 1) {
		size++;
		array_pointer = realloc(array_pointer, size * ENLARGE_SIZE);

		if (array_pointer == NULL) {
			printf("Error: memory reallocation failed\n");
			exit(1);
		}
		
		*(array_pointer + index) = number;
		index++;
	}

	array_pointer[0] = index - 1;
	return array_pointer;
}


void print_set(int *set_pointer, int number_of_elements) {
	int index = 1;;
	for (index; index <= number_of_elements; index++) {
		printf("%d ", *(set_pointer + index));
	}
}