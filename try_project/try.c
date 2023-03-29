#include <stdio.h>

int strlen(char *s) {
	char* p = s;
	while (*p != '\0')
		p++;
	return p - s;

}

main(void) {
	char my_string[] = "12";
	printf("%d", strlen(my_string));
}

