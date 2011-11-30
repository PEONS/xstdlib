/*  Sauvage Tao
    Data: 11/26/11
    Queue:
        Implementation of queue datatype, using SLL library */

#include <stdlib.h>
#include <Queue.h>

/* Creator & Destructor */
Queue create_queue(void* d)
{
    return create_list(d);
}

void delete_queue(Queue input)
{
    delete_list(input);
}

/* Queue functions */
/*  Return: (Queue) queue with one more element at the tail of the queue
    Data: input (Queue) queue which will receive the new tail
          d (void*) the data of the new element
    Process: use insert_tail from SLL library to add the new element */
Queue enter(Queue input, void* d)
{
    return insert_tail(input, d);
}

/*  Return: (Elem*) element of the head queue
    Data: input (Queue) queue to remove its head and produces the element
    Process: modify the queue pointer from the input to point to the
    new element of the queue. Meanwhile we save the element and return it */
Elem* delete(Queue *input)
{
    Elem *tailElem = NULL;

    if(!is_empty(*input))
    {
        tailElem = (Elem*)calloc(1, sizeof(Elem));
        tailElem->data = head(*input)->data;
        tailElem->next = NULL;
        *input = remove_head(*input);
    }

    return tailElem;
}

