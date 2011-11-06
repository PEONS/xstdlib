/*  Ruhier Anthony
	Date : 11/05/2011
	Utils */

#include <stdlib.h>
#include <stdio.h>
#include "../linked/simple-linked-list/SLL.h"
#include "utils.h"


/*  Return:
	Data: int lenght : the lenght of the array
		   void array : array you want to print
	Process:  */
void print_array(int l, int array[])
{
	int i = 0;

	printf("\n");

	for(i = 0; i < l; i++)
		printf(" %d ", array[i]);
}



/*  Return:
	Data: l List : list that's going to be print
	Process:  */
void print_list(List l)
{
    if(l == NULL)
        printf("List is empty");

    while(l->next != NULL)
        printf("%d ", *(int*)l->data);
}


