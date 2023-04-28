#include <stdio.h> 

int main() {
	char* my_string = "HEY";
	printf("SIZE: %d\n", sizeof(my_string) / sizeof(char));
	return 0;
}