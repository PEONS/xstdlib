/*  Sauvage Tao
	Date: 11/30/11
	Queue testfile:
		Test of queue implementation */

#include <stdlib.h>
#include <stdio.h>
#include <SLL.h>
#include <Queue.h>
#include <debug.h>

int main(void)
{
	int *a = malloc(sizeof(int)), *b = malloc(sizeof(int)), *c = malloc(sizeof(int));
	Queue q = NULL;
    Elem* temp = NULL;
	*a = 12;
    *b = 15;
    *c = 4;

    q = create_queue((void*)a);
    temp = (Elem*) calloc(1, sizeof(Elem));

	printf("1 - create_queue\tLength: %d\n", length_of(q));
    print_list_of_int(q);

	if(!is_empty(q))
	{
		q  = enter(q, (void*)b);
	    printf("\n2 - enter\tLength: %d\n", length_of(q));
        print_list_of_int(q);
    }
	else
	{
		printf("Unable to allocate a new queue\n");
		return 0;
	}

    q = enter(q, (void*)c);
	printf("\n3 - enter\tLength: %d\n", length_of(q));
    print_list_of_int(q);

    temp = delete(&q);
    printf("\n4 - delete\tLength: %d\n", length_of(q));
    if(!is_empty(temp))
        printf("temp->data = %d\n", *(int*)temp->data);
    print_list_of_int(q);
    free(temp);
    temp = NULL;

    temp = delete(&q);
    printf("\n5 - delete\tLength: %d\n", length_of(q));
    if(!is_empty(temp));
        printf("temp->data = %d\n", *(int*)temp->data);
    print_list_of_int(q);
    free(temp);
    temp = NULL;

    temp = delete(&q);
    printf("\n6 - delete\tLength: %d\n", length_of(q));
    if(!is_empty(temp));
        printf("temp->data = %d\n", *(int*)temp->data);
    print_list_of_int(q);
    free(temp);
    temp = NULL;

	q  = enter(q, (void*)b);
	printf("\n7 - enter\tLength: %d\n", length_of(q));
    print_list_of_int(q);

    delete_queue(q);
	free(a);
    free(b);
    free(c);
	return 0;
}

