#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structures can hold multiple variables
struct student{
    char name[40];
    int age;
};

void sayMaName(struct student student) {
    printf("My name is %s, and I am %d years old.\n", student.name, student.age);
}

// manipulates a student
void everyoneGetsOlder(struct student *student) { 
    (*student).age++;
}

int everyoneGetsOlder0(struct student student) { 
    student.age++;
    return student.age;
}

// Felix: 🌞



void manipulate(int *number, int factor) {
    *number *= factor;
}

int main(int argc, char const *argv[])
{
    struct student kevin;
    struct student marcus;


    strcpy(kevin.name, "Kevin");
    kevin.age = 12;

    int *kp;
    kp = &kevin.age;

    printf("%x\n", kp);

    strcpy(marcus.name, "Marcus");
    marcus.age = 22;

    sayMaName(kevin);
    sayMaName(marcus);

    kevin.age = everyoneGetsOlder0(kevin);
    everyoneGetsOlder(&kevin);

    sayMaName(kevin);

    int p = 3;
    manipulate(&p, 3);
    printf("%d\n", p);

    int v = 3;
    int *x;
    x = &v;
    printf("%d\n", (*x));

    return 0;
}
// int *p
// int *v = 3 v = adress v v = 3 p = &v (*p) = 3
//! Task: See weather
