#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h> 
#include <stdlib.h>
#define INT_SIZE sizeof(int)
#define ENLARGE_SIZE(size) ++size
#define INT_FOUND 1
#define MEMORY_ERROR 1
#define TRUE 1 
#define FALSE 0
								
struct dynamic_array {
	int size;
	int* array_pointer;
};

struct dynamic_array get_set();
void add_number_to_array(struct dynamic_array* my_array, int number);
int number_in_array(struct dynamic_array my_array, int number);
void print_set(struct dynamic_array set);
void print_full_array(struct dynamic_array full_array);

int main(void) {
	struct dynamic_array set;
	set = get_set();
	print_set(set);

}

struct dynamic_array get_set() {
	struct dynamic_array set = {0, NULL};
	struct dynamic_array full_array = {0, NULL};
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


void print_set(struct dynamic_array set) {
	int index;
	printf("Set is:\n");

	for (index = 0; index < set.size; index++)
		printf("%d ", *(set.array_pointer + index));

	printf("\n");
}

void print_full_array(struct dynamic_array full_array) {
	int index;
	printf("Full array is:\n");

	for (index = 0; index < full_array.size; index++)
		printf("%d ", *(full_array.array_pointer + index));

	printf("\n");
}


void add_number_to_array(struct dynamic_array* my_array, int number) {
	if (my_array->size == 0) {
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