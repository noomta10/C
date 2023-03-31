#include <stdio.h> 


main()
{
	// DOES NOT WORK
	char* y = "1234";
	char x[] = y;

	// WORKS
	char y[] = "1234";
	char* x = y;
}