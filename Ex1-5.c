#include <stdio.h>
/* print Fahrenheit-Celsius table in reverse order */
/* from 300 down to 0 with decremental step of 20 */
main0()
{
	int fahr;
	for (fahr = 300; fahr >= 0; fahr = fahr - 20)
		printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
}