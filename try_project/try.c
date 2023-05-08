#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main(void) {
	int day, month, year;

	printf("Enter date\n");
	scanf("%d/%d/%d", &day, &month, &year);
	printf("%d", day);
}

