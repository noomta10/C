#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>
#define ENLARGE_SIZE sizeof(int)


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
	int size = 1; // initial value of array
	int* array_pointer = malloc(size * ENLARGE_SIZE); // allocate memory for the array

	if (array_pointer == NULL) {
		printf("Error: memory allocation failed\n");
		exit(1);
	}

	printf("Enter numbers:\n ");
	while (scanf("%d", &number) == 1) {
		if (count == size) {
			size += ENLARGE_SIZE;
			array_pointer = realloc(array_pointer, size);

			if (array_pointer == NULL) {
				printf("Error: memory reallocation failed\n");
				exit(1);
			}
		}
		
		array_pointer[count++] = number;
	}
	array_pointer[count++] = '\0';
	return array_pointer;
}



void print_set(int *array) {
	for (int i = 0; array[i] != '\0' ; i++) {
		printf("%d ", array[i]);
	}
}