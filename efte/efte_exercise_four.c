#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ENTRY_SIZE 100

/*
* Resources:
* https://www.learn-c.org/de/Dynamic%20allocation
* http://www.c-howto.de/tutorial/arrays-felder/speicherverwaltung/
* http://www.c-howto.de/tutorial/variablen/typumwandlung/
* https://www.youtube.com/watch?v=lQP4X3odvHE
*/


typedef struct
{
    char content[ENTRY_SIZE];
    int check;   
} entry;


void fail(void)
{
    printf("Memory cannot be allocated");
    exit(EXIT_FAILURE);
}

//! Task
void append(int *dest, int source, size_t *n)
{
    (*n)++;
    dest = realloc(dest, (sizeof(int)*(*n)));
    if (dest == NULL) exit(1);
    dest[(*n)-1] = source;
}


int main(int argc, char const *argv[])
{
    size_t n = 3;
    int *arr = calloc(n, sizeof(int));
    if (arr == NULL) exit(1);
    append(arr, 4, &n);
    append(arr, 5, &n);

    for (size_t i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }

    free(arr);


    return 0;
}

