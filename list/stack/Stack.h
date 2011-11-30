#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

/*  Sauvage Tao
    Data: 11/26/11
    Stack:
        Declaration of stack datatype, using SLL library */

#include <SLL.h>

typedef List Stack;

/* Creator & Destructor */
Stack create_stack(void*);
void delete_stack(Stack);
/* Stack functions */
Stack push(Stack, void*);
Elem* pop(Stack*);

#endif /* STACK_H_INCLUDED */

