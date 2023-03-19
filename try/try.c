#include <stdio.h>
#include <math.h>

#define ALON(x) if (x>0) {printf("Alon is %d\n",x);}

int main() {
	int i = 5;
	ALON(i++);
	ALON(i++);
}

