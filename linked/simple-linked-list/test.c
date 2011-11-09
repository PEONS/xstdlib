/*  Sauvage Tao
	Date: 11/05/11
	Simple linked list testfile:
		Test of simple linked list implementation */

#include <stdlib.h>
#include <stdio.h>
#include "SLL.h"
#include "../../debug/debug.h"

int main(void)
{
	int *a = malloc(sizeof(int)), *b = malloc(sizeof(int));
	List l = NULL;
	*a = 12;
    *b = 15;
	l = create_list((void*)a);

	printf("Length: %d\n", length_of(l));
    print_list_of_int(l);

	if(!is_empty(l))
	{
		l  = insert_head(l, (void*)b);
	    printf("Length: %d\n", length_of(l));
        print_list_of_int(l);
    }
	else
	{
		printf("Unable to allocate a new list\n");
		return 0;
	}

    l = insert_tail(l, (void*)b);
	printf("\nLength: %d\n", length_of(l));
    print_list_of_int(l);

    l = insert_head(l, (void*)b);
    printf("\nLength: %d\n", length_of(l));
    print_list_of_int(l);

    l = insert_of(l, (void*)a, 2);
    printf("\nLength: %d\n", length_of(l));
    print_list_of_int(l);

    l = remove_of(l, 2);
    printf("\nLength: %d\n", length_of(l));
    print_list_of_int(l);

    l = reverse(l);
    printf("\nLength: %d\n", length_of(l));
    print_list_of_int(l);

    printf("\nLength: %d\n", length_of(l));
    print_list_of_int(l);

    delete_list(l);
	free(a);
    free(b);
	return 0;
}

