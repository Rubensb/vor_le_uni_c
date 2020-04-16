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
    

}

int main(int argc, char const *argv[])
{
    int checkListSize;
    printf("Please enter the amount of entries in your checklist: ");
    scanf("%d", &checkListSize);

    entry *checkList = (entry*)malloc(checkListSize * sizeof(entry));
    //int *check2 = calloc(3, sizeof(int)); 
    if (checkList == NULL) fail();
    
    for (size_t i = 0; i < checkListSize; i++)
    {
        printf("Entry %d: ", (int)i);
        scanf("%s", &checkList[(int) i].content);
        checkList[(int) i].check = 0;
    }

    checkListSize += 2;
    checkList = realloc(checkList, checkListSize);
    strcpy(checkList[checkListSize-1].content, "Hallo");
    strcpy(checkList[checkListSize-2].content, "Hallo2");

    for (size_t i = 0; i < checkListSize; i++)
    {
        printf("%s\n", checkList[i].content);
    }


    int *arr = malloc(3 * sizeof(int));
    append(arr, 4, 3);


    free(checkList);

    

    return EXIT_SUCCESS;
}
