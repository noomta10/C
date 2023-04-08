#include <stdio.h>

struct person {
	char name[50];
	int age;
};

int main() {
	struct person my_person = { "Noam Tamir", 20 };
	struct person* my_person_pointer = &my_person;

	printf("Name: %s\n", my_person_pointer->name);
	printf("Name: %s\n", (*my_person_pointer).name);


	return 0;
}
