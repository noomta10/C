#include <stdio.h>

int rightrot(int x, int n);

int main() {
	printf("%d", rightrot(10, 2));
}

int rightrot(int x, int n) {
	return x >> n;
}