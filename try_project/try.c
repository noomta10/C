#include <stdio.h>

struct person {
	int a;
	char i[10];
	float i1;
};

int main() {
	struct person p;
	printf("%d\n", sizeof(p));



	return 0;
}
