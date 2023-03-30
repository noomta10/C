#include <stdio.h>

void strncpy(char *dest, char* src, int number_of_characters);
void strncat(char* dest, char* src, int number_of_characters);
int strncmp(char* string1, char* string2, int number_of_characters);



int main() {
	char dest[20] = "abcde";
	char src[20] = "12345";
	//printf("Destination: %s\n", dest);
	//strncpy(dest, src, 2);
	//printf("New destination: %s\n", dest);

	//printf("Destination: %s\n", dest);
	//strncat(dest, src, 6);
	//printf("New destination: %s\n", dest);

	char string1[] = "123abc456";
	char string2[] = "abcdefghi";
	printf("Strncmp return value: %d ", strncmp(string1 + 3, string2, 3));

	return 0;
}

/* Copy n chars from src to dest */
void strncpy(char* dest, char* src, int number_of_characters) {
	while (*dest != '\0' && number_of_characters-- > 0) {
		*dest++ = *src++;
	}
}

/* Concatenate n chars from src to dest */
void strncat(char* dest, char* src, int number_of_characters) {
	while (*dest != '\0')
		dest++;

	while ((*dest++ = *src++) != '\0' && --number_of_characters > 0)
		;

	*dest = '\0';
}

/* Compare n chars of string 1 to string 2 */
int strncmp(char* string1, char* string2, int number_of_characters) {

	for (; *string1 == *string2; string1++, string2++) {
		if (*string1 == '\0' || --number_of_characters <= 0)
			return 0;
	}

	return (*string1 - *string2);
}