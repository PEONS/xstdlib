/*  Sauvage Tao
    Data: 11/26/11
    Stack:
        Implementation of stack datatype, using SLL library */

#include <stdlib.h>
#include <Stack.h>

/* Creator & Destructor */
Stack create_stack(void* d)
{
    return create_list(d);
}

void delete_stack(Stack input)
{
    delete_list(input);
}

/* Stack functions */
/*  Return: (Stack) stack with one more element at the head of the stack
    Data: input (Stack) stack which will receive the new head
          d (void*) the data of the new element
    Process: use insert_head from SLL library to add the new element */
Stack push(Stack input, void* d)
{
    return insert_head(input, d);
}

/*  Return: (Elem*) element of the head stack
    Data: input (Stack) stack to remove its head and produces the element
    Process: modify the stack pointer from the input to point to the
    new element of the stack. Meanwhile we save the element and return it */
Elem* pop(Stack *input)
{
    Elem *headElem = NULL;

    if(!is_empty(*input))
    {
        headElem = (Elem*)calloc(1, sizeof(Elem));
        headElem->data = head(*input)->data;
        headElem->next = NULL;
        *input = remove_head(*input);
    }

    return headElem;
}

