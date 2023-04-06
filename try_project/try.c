#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int add(int a, int b) {
    return a + b;
}

int mul(int a, int b) {
    return a * b;
}

int main() {
    int (*fun)(int, int); // A pointer to a function
    fun = mul;
    printf("%d\n", fun(5, 7));
    return 0;
}
