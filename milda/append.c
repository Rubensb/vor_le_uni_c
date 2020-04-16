#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//int *arr = malloc(3 * sizeof(int));
//append(arr, 4, 3);

//! Task
void append(int *dest, int source, size_t *n)
{
    (*n)++;
    dest = realloc(dest, sizeof(int)*(*n));
    if ((*dest) == 0) exit(1);
    dest [(*n)-1] = source;
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