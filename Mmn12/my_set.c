#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>
#define ENLARGE_SIZE sizeof(int);


int* get_set(void);
void print_set(int* array);

int main() {
	int* set = get_set();
	print_set(set);

}

// create a set
int* get_set(void) {
	int number; // users number
	int count = 0; // count all numbers entered by the user
	int size = 1; // Initial value of array
	int* array = malloc(size * sizeof(int)); // allocate memory for the array

	if (array == NULL) {
		printf("Error: memory allocation failed\n");
		exit(1);
	}

	printf("Enter numbers:\n ");
	while (scanf("%d", &number) == 1) {
		if (count == size) {
			size += ENLARGE_SIZE;
			array = realloc(array, size);

			if (array == NULL) {
				printf("Error: memory reallocation failed\n");
				exit(1);
			}
		}
		
		array[count++] = number;
	}

	return array;
}



void print_set(int *array) {
	int count = 5;
	for (int i = 0; i < count; i++) {
		printf("%d ", array[i]);
	}
}