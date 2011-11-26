/*  Sauvage Tao
    Data: 11/26/11
    Queue:
        Implementation of queue datatype, using SLL library */

#include "Queue.h"

/* Queue functions */
/*  Return: (List) list with one more element at the tail of the list
    Data: input (List) list which will receive the new tail
          d (void*) the data of the new element
    Process: use insert_tail from SLL library to add the new element */
List enter(List input, void* d)
{
    return insert_tail(input, d);
}

/*  Return: (Elem*) element of the tail list
    Data: input (List) list to remove its tail and produces the element
    Process: modify the list pointer from the input to point to the
    new element of the list. Meanwhile we save the element and return it */
Elem* delete(List input)
{
    Elem *tailElem = NULL;

    if(!is_empty(input))
    {
        tailElem = tail(input);
        input = remove_tail(input);
    }

    return tailElem;
}

