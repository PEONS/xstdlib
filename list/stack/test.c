/*  Sauvage Tao
	Date: 11/30/11
	Stack testfile:
		Test of stack implementation */

#include <stdlib.h>
#include <stdio.h>
#include <SLL.h>
#include <Stack.h>
#include <debug.h>

int main(void)
{
	int *a = malloc(sizeof(int)), *b = malloc(sizeof(int)), *c = malloc(sizeof(int));
	Stack s = NULL;
    Elem* temp = NULL;
	*a = 12;
    *b = 15;
    *c = 4;

    s = create_stack((void*)a);
    temp = (Elem*) calloc(1, sizeof(Elem));

	printf("1 - create_stack\tLength: %d\n", length_of(s));
    print_list_of_int(s);

	if(!is_empty(s))
	{
		s  = push(s, (void*)b);
	    printf("\n2 - push\tLength: %d\n", length_of(s));
        print_list_of_int(s);
    }
	else
	{
		printf("Unable to allocate a new stack\n");
		return 0;
	}

    s = push(s, (void*)c);
	printf("\n3 - push\tLength: %d\n", length_of(s));
    print_list_of_int(s);

    temp = pop(&s);
    printf("\n4 - pop\tLength: %d\n", length_of(s));
    if(!is_empty(temp))
        printf("temp->data = %d\n", *(int*)temp->data);
    print_list_of_int(s);
    free(temp);
    temp = NULL;

    temp = pop(&s);
    printf("\n5 - pop\tLength: %d\n", length_of(s));
    if(!is_empty(temp));
        printf("temp->data = %d\n", *(int*)temp->data);
    print_list_of_int(s);
    free(temp);
    temp = NULL;

    temp = pop(&s);
    printf("\n6 - pop\tLength: %d\n", length_of(s));
    if(!is_empty(temp));
        printf("temp->data = %d\n", *(int*)temp->data);
    print_list_of_int(s);
    free(temp);
    temp = NULL;

	s  = push(s, (void*)b);
	printf("\n7 - push\tLength: %d\n", length_of(s));
    print_list_of_int(s);

    delete_stack(s);
	free(a);
    free(b);
    free(c);
	return 0;
}

