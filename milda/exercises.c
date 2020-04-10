//! Task: Write a function which calculates the sum of three double arguments and prints it to stdout
//! Task: Write a program which determines if a number is even or odd using argc and argv
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void zusammen(double o, double t, double th)
{
    double zus = o + t + th;
    printf("%f\n", zus);
}

int main(int argc, char const *argv[])
{

    int a = atoi(argv[1]);

    if (argc == 1)
    {
        printf("Nichts\n");
    }

    else if (a % 2 == 1)
    {
        printf("Odd numbers before %d : ", a);
    }

    else
    {
        printf("Even numbers before %d : ", a);
    }

    for (int i = a - 2; i > 0; i -= 2)
    {
        printf("%d ", i);
    }

    printf("\n");

    //double e, z, d;
    //scanf("%lf", &e);
    //scanf("%lf", &z);
    //scanf("%lf", &d);

    //zusammen (e,z,d);
    return 0;
}