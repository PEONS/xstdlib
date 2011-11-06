/*  Sauvage Tao
	Date: 11/05/11
	Simple linked list testfile:
		Test of simple linked list implementation */

#include <stdlib.h>
#include <stdio.h>
#include "SLL.h"

int main(void)
{
	int *a = malloc(sizeof(int));
	List l = NULL;
	*a = 12;
	l = create_list((void*)a);

	printf("Length: %d\n", length_of(l));

	*a = 15;
	if(!is_empty(l))
	{
		l  = insert_head(l, (void*)a);
	}
	else
	{
		printf("Unable to allocate a new list\n");
		return 0;
	}


	printf("Length: %d\n", length_of(l));
    l = insert_tail(l, (void*)a);
	printf("Length: %d\n", length_of(l));
    l = insert_of(l, (void*)a, 2);
	printf("Length: %d\n", length_of(l));
    l = remove_of(l, 2);
	printf("Length: %d\n", length_of(l));
    l = reverse(l);
	printf("Length: %d\n", length_of(l));

    delete_list(l);
	free(a);
	return 0;
}

