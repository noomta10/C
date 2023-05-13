#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 

int f2() {
	static int k = 0;
	k++;
	printf("%d\n", k);
}

int main() {
	for (int i = 0; i < 10; i++) {
		f2();
	}

	return 0;
}