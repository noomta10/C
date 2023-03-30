#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char source[10] = "123";
	char destination[10] = "abcde";

	printf("destination is originally = '%s'\n", destination);
	strncpy(destination, source, 5);
	printf("After strncpy, destination becomes '%s'\n", destination);

	return(0);
}