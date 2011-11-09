/*  Ruhier Anthony, Sauvage Tao
    Date: 11/09/11
    Debug:
        Implementation of debug functions */

#include <stdio.h>
#include "debug.h"

void print_array_of_int(int array[], int length)
{
    int i = 0;

    printf("Values of the array:\n\t");
    for(i = 0; i < length; i = i + 1)
        printf("%d ", array[i]);
    printf("\n");
}

void print_list_of_int(List input)
{
    Elem *current = NULL;

    if(is_empty(input))
        printf("List is empty\n");
    else
    {
        current = input;
        printf("Values of the list:\n\t");
        while(current != NULL)
        {
            printf("%d ", *(int*)current->data);
            current = current->next;
        }
        printf("\n");
    }
}

