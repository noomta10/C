#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h> 
#include <stdlib.h>
#define INT_SIZE sizeof(int)
#define ENLARGE_SIZE(size) ++size
#define INT_FOUND 1
#define MEMORY_ERROR 1
#define FIRST_INDEX 0
#define NUMBER_EXISTS 1 
#define NUMBER_DOESNT_EXIST 0
								
struct dynamic_array {
	int size;
	int* array_pointer;
};

struct dynamic_array get_set();
void add_number_to_array(struct dynamic_array* my_array, int number);
int number_in_array(struct dynamic_array my_array, int number);
void print_set(struct dynamic_array set);

int main(void) {
	struct dynamic_array set;
	set = get_set();
	printf("%d", set.size);
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
	return set;
}


void print_set(struct dynamic_array set) {
	int index;
	printf("Set is:\n");

	for (index = FIRST_INDEX; index < set.size; index++)
		printf("%d ", *(set.array_pointer + index));

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
	
	*my_array->array_pointer = number;
	my_array->array_pointer++;
		
}


int number_in_array(struct dynamic_array my_array, int number) {
	int index;

	for (index = FIRST_INDEX; index < my_array.size; index++) {
		if (*(my_array.array_pointer + index) == number)
			return NUMBER_EXISTS;
	}

	return NUMBER_DOESNT_EXIST;
}