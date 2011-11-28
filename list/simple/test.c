/*  Sauvage Tao
	Date: 11/05/11
	Simple linked list testfile:
		Test of simple linked list implementation */

#include <stdlib.h>
#include <stdio.h>
#include <SLL.h>
#include <debug.h>

int main(void)
{
	int *a = malloc(sizeof(int)), *b = malloc(sizeof(int)), *c = malloc(sizeof(int));
	List l = NULL;
	*a = 12;
    *b = 15;
    *c = 4;
	l = create_list((void*)a);

	printf("1 - create_list\tLength: %d\n", length_of(l));
    print_list_of_int(l);

	if(!is_empty(l))
	{
		l  = insert_head(l, (void*)b);
	    printf("\n2 - insert_head\tLength: %d\n", length_of(l));
        print_list_of_int(l);
    }
	else
	{
		printf("Unable to allocate a new list\n");
		return 0;
	}

    l = remove_tail(l);
	printf("\n3 - remove_tail\tLength: %d\n", length_of(l));
    print_list_of_int(l);

    l = insert_head(l, (void*)a);
    printf("\n4 - insert_head\tLength: %d\n", length_of(l));
    print_list_of_int(l);

    l = insert_of(l, (void*)c, 2);
    printf("\n5 - insert_of\tLength: %d\n", length_of(l));
    print_list_of_int(l);

    l = remove_of(l, 2);
    printf("\n6 - remove_of\tLength: %d\n", length_of(l));
    print_list_of_int(l);

    l = reverse(l);
    printf("\n7 - reverse\tLength: %d\n", length_of(l));
    print_list_of_int(l);

    delete_list(l);
	free(a);
    free(b);
    free(c);
	return 0;
}

