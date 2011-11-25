#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

/*  Sauvage Tao
    Data: 11/26/11
    Stack:
        Declaration of stack datatype, using SLL library */

#include "SLL.h"

/* Stack functions */
List push(List, void*);
Elem* pop(List);

#endif /* STACK_H_INCLUDED */

