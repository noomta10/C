#include <stdio.h>

void strncpy(char *dest, char* src, int number_of_characters);
void strncat(char* dest, char* src, int number_of_characters);



int main() {
	char dest[10] = "abcde";
	char src[10] = "123";
	//printf("Destination: %s\nSource: %s\n\n", dest, src);
	//strncpy(dest, src, 2);
	//printf("Destination: %s\nSource: %s\n", dest, src);

	printf("Destination: %s\n", dest);
	strncat(dest, src, 2);
	printf("New destination: %s\n", dest);

	return 0;
}

void strncpy(char* dest, char* src, int number_of_characters) {
	while (*dest != '\0' && number_of_characters-- > 0) {
		*dest++ = *src++;
	}
}

void strncat(char* dest, char* src, int number_of_characters) {
	while (*dest != '\0')
		dest++;

	while ((*dest++ = *src++) != '\0' && number_of_characters-- > 0)
		;

}


