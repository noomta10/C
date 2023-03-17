#include <stdio.h>
#define MAX 300
float celsius(float fahr);

/* Create a tempersture convertor with function to convert to celsius */

main() {
	float fahr;

	printf("%5s %5s\n", "Fahr", "Celsius");

	for (fahr = 0; fahr < MAX; fahr += 20) {
		printf("%3.0f %6.1f\n", fahr, celsius(fahr));
	}
}

float celsius(float fahr)
{
	return (5.0 / 9.0) * (fahr - 32);
}