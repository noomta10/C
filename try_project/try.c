#include <stdio.h> 

struct user_st {
	int age;
	char* name;
};
typedef struct user_st user;

int main() {
	user noam = { 20, "noam" };

	return 0;
}