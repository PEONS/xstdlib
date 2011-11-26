#ifndef SSL_H_INCLUDED
#define SSL_H_INCLUDED

/*  Sauvage Tao
	Date: 11/05/11
	Simple Linked List:
		Declaration of simple linked list datatype */

#include "../../utils/utils.h"

typedef struct elem
{
	void *data;
	struct elem* next;
} Elem;

typedef Elem* List;

/* Creator & Destructor */
List create_list(void*);
void delete_list(List);
/* Accessor */
Elem* head(List);
void* head_value(List);
Elem* tail(List);
void* tail_value(List);
Bool is_empty(List);
int length_of(List);
/* Modifiers */
List insert_of(List, void*, int);
List insert_head(List, void*);
List insert_tail(List, void*);
List remove_of(List, int);
List remove_head(List);
List remove_tail(List);
List reverse(List);

#endif /* SSL_H_INCLUDED */

