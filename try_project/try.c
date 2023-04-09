#include <stdio.h>

struct Person {
    char name[50];
    int age;
};

void change_age_by_value(struct Person p) {
    p.age = 99;
}

void change_age_by_ref(struct Person* p) {
    p->age = 100;
}

int main() {
    struct Person alice = { "Alice", 25 };
    change_age_by_ref(&alice);
    printf("Name: %s, Age: %d\n", alice.name, alice.age);

    return 0;
}

