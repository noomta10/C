#include <stdio.h>

void reverse(char string[]);
void reverse1(char string[], int start, int end);

int main() {
	char my_string[] = "Hello world";
	printf("Before reverse: %s\n", my_string);
	reverse(my_string);
	printf("After reverse: %s", my_string);
}


void reverse(char string[]) {
	int string_length;
	
	for (string_length = 0; string[string_length] != '\0'; string_length++)
		;

	reverse1(string, 0, string_length - 1);
}


void reverse1(char string[], int start, int end) {
	int temp;

	if (end - start > 0) {
		temp = string[start];
		string[start] = string[end];
		string[end] = temp;
		reverse1(string, start + 1, end - 1);
	}
}
