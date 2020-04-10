#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// the main function can also be called with arguments
// argc is the number of arguments comming in
// argv are the actual values stored in an array
int main(int argc, char const *argv[])
{
    // Conditional execution
    // Checks if there are enough arguments
    if (argc == 3)
    {
        // atoi(char) converts a char to an int
        int a = atoi(argv[1]);
        int b = atoi(argv[2]);
        printf("%d\n", (a + b));

        
        // compare with ==, !=, <, >, <=, >=
        // combine conditions with &&, ||
        if (a > b)
        {
            printf("a > b\n");
        }
        else if (a < b)
        {
            printf("a < b\n");
        }
        else
        {
            printf("a == b\n");
        }
    }

    int acc = 0;

    // Loops
    for (int i = 0; i < 10; i++)
    {
        acc += 1;
    }

    printf("%lf", (3.5/2));
    

    return 0;
}

//! Task: Write a program which determines if a number is even or odd using argc and argv
//! If the number is odd printout all odd predecessors and vice versa

//! Input: 6
//! Output: Even numbers before 6: 4 2 

//! Input: 9
//! Output: Odd numbers before 9: 7 5 3 1 
