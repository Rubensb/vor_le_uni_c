// #include <libary.h> includes all functions of "libary"
// e.g. stdio.h, stdlib.h, string.h, math.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Preprocessor variables are inserted before the code is compiled
#define SOME_VALUE 3 


// basic function structure
// void is beeing used for functions without any return value
void printBlaBla(int age) {
    printf("Great, %d is an exiting age!\n", age);
}


int main() 
{

    // declaration of a variable without definition
    int k; 

    // definition of a variable
    k = 100;

    // decleration and definiton at once
    int j = 200;

    // declaring multiple variables at once
    int i, o;

    // This value cannot be changed
    const double pi = 3.14;

    // basic types

    int a = 0;
    float b = 0.5;
    double c = 3.549943;

    // Array declaration and definition
    // type name[max_amount_of_elements] = { firstelement, secondelement, ... }
    int d[5] = { 0, 2, 3, 3, 5 };

    // Single elements can be accessed by its index (index starts at 0)
    int e = d[2];

    char f = 'd';

    // Strings are represented as arrays 
    char g[40] = "Hello";

    // One way to manipulate strings
    strcpy(g, "Hello, how old are you?");


    // I/O
    // printf prints to stdout using format specifiers for variables
    // List of format specifers: https://codeforwin.org/2015/05/list-of-all-format-specifiers-in-c-programming.html
    printf("Hallo %s\n", g);

    // read userintput
    int userinput;
    scanf("%d", &userinput);

    // function call with userinput as argument
    printBlaBla(userinput);

    // when main() is finished without any issues it should return 0
    return 0;
}


//! Task: Write a function which calculates the sum of three double arguments and prints it to stdout