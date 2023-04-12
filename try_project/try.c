#include <stdio.h> 

struct struct2 {
	int member1 : 1;
	int member2 : 1;
};

int main() {
	struct struct2 struct2;
	printf("Size of struct2: %zu\n", sizeof(struct2));


	return 0;
}