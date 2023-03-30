#include <stdio.h>

void strcat(char *s, char *t);

int main() {
	char string1[10] = "abc";
	char string2[10] = "def";

	printf("String 1: %s\nString 2: %s\n\n", string1, string2);
	strcat(string1, string2);
	printf("After strcat:\nString 1: %s\nString 2: %s\n", string1, string2);

}

void strcat(char* s, char* t) {
	while (*s != '\0')
		s++;

	while ((*s++ = *t++) != '\0')
		;
}
