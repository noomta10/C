#define _CRT_SECURE_NO_WARNINGS
#define OK 0
#define STEP 2


/* Count_bits is a function that sums up and returns the number of bits that are on, on the even places,
in an unsigned long variable.
The function gets an unsigned long number and use bitwise operators AND and RIGHT SHIFT (until the number becomes zero).
Returns the number of bits on the even places are on.
We assume that the number the function recives is not larger than max value of unsigned long (4294967295) */
int reset_bit_index(unsigned long number); 