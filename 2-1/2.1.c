#include <stdio.h>
#include <limits.h>

main()
{
	printf("The range of signed char is from %d to %d\n", SCHAR_MIN, SCHAR_MAX);
	printf("The range of unsigned char is from %d to %d\n", 0, UCHAR_MAX);

	printf("The range of int is from %d to %d\n", INT_MIN, INT_MAX);
	printf("The range of unsigned int is from %d to %u\n", 0, UINT_MAX);

	printf("The range of short is from %d to %d\n", SHRT_MIN, SHRT_MAX);
	printf("The range of unsigned short is from %d to %u\n", 0, USHRT_MAX);

	printf("The range of long is from %ld to %ld\n", LONG_MIN, LONG_MAX);
	printf("The range of unsigned long is from %d to %lu\n", 0, ULONG_MAX);
}