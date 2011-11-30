#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

/*  Sauvage Tao
    Data: 11/26/11
    Queue:
        Declaration of queue datatype, using SLL library */

#include <SLL.h>

typedef List Queue;

/* Creator & Destructor */
Queue create_queue(void*);
void delete_queue(Queue);
/* Queue functions */
Queue enter(Queue, void*);
Elem* delete(Queue*);

#endif /* QUEUE_H_INCLUDED */

