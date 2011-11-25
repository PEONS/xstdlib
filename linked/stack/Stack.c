/*  Sauvage Tao
    Data: 11/26/11
    Stack:
        Implementation of stack datatype, using SLL library */

#include "Stack.h"

/* Stack functions */
/*  Return: (List) list with one more element at the head of the list
    Data: input (List) list which will receive the new head
          d (void*) the data of the new element
    Process: use insert_head from SLL library to add the new element */
List push(List input, void* d)
{
    return insert_head(input, data);
}

/*  Return: (Elem*) element of the head list
    Data: input (List) list to remove its head and produces the element
    Process: modify the list pointer from the input to point to the
    new element of the list. Meanwhile we save the element and return it */
Elem* pop(List input)
{
    Elem *headElem = NULL, *temp = NULL;

    if(!is_empty(input))
    {
        headElem = head(input);
        temp = input;
        input = input->next;
        free(temp);
        temp = NULL;
    }

    return headElem;
}

