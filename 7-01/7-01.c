/* Converts input to upper case or lower case. (if argv[1] begins with U or u)  */

#include <stdio.h>
#include <ctype.h>

void to_lower_function(void);
void to_upper_function(void);


int main(int argc, char* argv[]) {
	if (argc > 1) {
		if (strcmp(argv[1], "u") == 0)
			to_lower_function();
		else if (strcmp(argv[1], "U") == 0)
			to_upper_function();
	}
	else {
		printf("Unknown parameter\n");
		return (- 1);
	}
}

void to_lower_function(void) {
	int c;

	while ((c = getchar()) != EOF) {
		putchar(tolower(c));
	}
}

void to_upper_function(void) {
	int c;

	while ((c = getchar()) != EOF) {
		putchar(toupper(c));
	}
}