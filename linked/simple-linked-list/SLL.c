/*  Sauvage Tao
	Data: 11/05/11
	Simple Linked List:
		Implementation of simple linked list datatype */

#include <stdlib.h>
#include <stdio.h>
#include "SLL.h"

/* Creator & Destructor */
/*  Return: (List) list newly created
	Data:
	Process: allocate memory to create new list */
List create_list(void* d)
{
	List l = NULL;
	l = (Elem*)calloc(1, sizeof(Elem));

	if(l != NULL)
	{
		l->next = NULL;
		l->data = d;
	}

	return l;
}

/*  Return:
	Data: l (List) list to delete
	Process: travers the list to free each element */
void delete_list(List l)
{
	Elem *p = NULL, *q = NULL;

	if(l != NULL)
	{
		p = l;
		while(p->next != NULL)
		{
			q = p;
			p = p->next;
			free(q);
			q = NULL;
		}
	}
}

/* Accessor */
/*  Return: (Elem*) head of the list
	Data: l (List) list to process
	Process: process the list to return the first element */
Elem* head(List l)
{
	if(l != NULL)
		return (Elem*)l;
	return l;
}

/*  Return: (void*) data of the head of the list
	Data: l (List) list to process
	Process: process the list to return the data of first element */
void* head_value(List l)
{
	if(l != NULL)
		return l->data;
	return NULL;
}

/*  Return: (Elem*) tail of the list
	Data: l (List) list to process
	Process: travers the list to reach the last element and return it */
Elem* tail(List l)
{
	Elem *p = NULL;

	if(l != NULL)
	{
		p = l;
		while(p->next != NULL)
			p = p->next;
		return p;
	}
	return NULL;
}

/*  Return: (void*) data of tail of the list
	Data: l (List) list to process
	Process: travers the list to reach the last element
	and return its data value */
void* tail_value(List l)
{
	Elem *p = NULL;

	if(l != NULL)
	{
		p = l;
		while(p->next != NULL)
			p = p->next;
		return p->data;
	}
	return NULL;
}

/*  Return: (Bool) true if the list is empty, otherwise false
	Data: l (List) list to test
	Process: test if the list pointer is equal to NULL */
Bool is_empty(List l)
{
	return (l == NULL) ? TRUE : FALSE;
}

/*  Return: (int) the number of element into the list
	Data: l (List) list where elements have to be counted
	Process: travers the list to increment the length and return it */
int length_of(List l)
{
	Elem *p = NULL;
	int i = 0;

	if(l != NULL)
	{
		p = l;
		while(p->next != NULL)
		{
			p = p->next;
			i = i + 1;
		}
		return i + 1;
	}
	return 0;
}

/* Modifiers */
/*  Return: (List) list with one more element
	Data: l (List) list which will receive the new element
		  d (void*) the data of the new element
		  n (int) the index of the new element position
	Process: travers the list to reach the n-th place and add the new element */
List insert_of(List l, void* d, int n)
{
	Elem *p = NULL, *q = NULL, *tmp = NULL;
	int i = 0;

	if(l != NULL)
	{
		p = l;
		while(p->next != NULL && i <= n)
		{
			p = p->next;
			i = i + 1;
		}
		q = (Elem*)calloc(1, sizeof(Elem));
		q->data = d;
		if(q != NULL)
		{
			if(i == n)
			{
				tmp = p->next;
				p->next = q;
				q->next = tmp;
			}
			else
			{
				p->next = q;
				q->next = NULL;
			}
		}
	}
	return l;
}

/*  Return: (List) list with one more element at the head of the list
	Data: l (List) list which will receive the new head
		  d (void*) the data of the new element
	Process: add a new element at the head of the list */
List insert_head(List l, void* d)
{
	Elem *p = NULL;

	p = (Elem*) calloc(1, sizeof(Elem));
	if(p != NULL)
	{
		p->next = l;
		p->data = d;
	}
	return p;
}

/*  Return: (List) list with one more element at the tail of the list
	Data: l (List) list which will receive the new tail
		  d (void*) the data of the new element
	Process: travers the list to reach its end, then add the new element */
List insert_tail(List l, void* d)
{
	Elem *p = NULL, *q = NULL;

	if(l == NULL)
		return insert_head(l, d);
	else
	{
		p = (Elem*) calloc(1, sizeof(Elem));
		if(p != NULL)
		{
			p->data = d;
			p->next = NULL;
			q = l;
			while(q->next != NULL)
				q = q->next;
			q->next = p;
		}
	}
	return l;
}

/*  Return: (List) list with one less element
	Data: l (List) list which will have one less element
		  n (int) the index of the element which will be deleted
	Process: travers the list to reach the n-th element and free it */
List remove_of(List l, int n)
{
	Elem *p = NULL, *q = NULL, *tmp = NULL;
	int i = 0;

	if(l != NULL)
	{
		p = l;
		while(p->next != NULL && i < n)
		{
			p = p->next;
			i = i + 1;
		}
		if(p->next != NULL)
		{
			tmp = p;
			p = p->next;
			q = p;
			p = p->next;
			tmp->next = p;
			free(q);
			q = NULL;
		}
	}
	return l;
}

/*  Return: (List) list without the head
	Data: l (List) list which will have its head removed
	Process: free the head of the list */
List remove_head(List l)
{
	Elem *p = NULL;

	if(l != NULL)
	{
		p = l;
		p = p->next;
		free(l);
		l = NULL;
		return p;
	}
	return l;
}

/*  Return: (List) list without the tail
	Data: l (List) list which will have its tail removed
	Process: travers the list and free the last element reached */
List remove_tail(List input)
{
    Elem* current = input;

	if(input != NULL)
    {
	    if(input->next != NULL)
        {
            while(current->next->next != NULL)
                current = current->next;

            free(current->next);
            current->next = NULL;
        }
        else
        {
            free(input);
            return NULL;
        }
    }

    return input;
}

/*  Return: (List) list reversed
	Data: l (List) list to reverse
	Process: travers the list to change each next pointer value */
List reverse(List l)
{
	List tmp = NULL;
	Elem *p = NULL;

	if(l != NULL)
	{
		tmp = l;
		p = l;
		while(p->next != NULL)
		{
			tmp = insert_head(p, p->data);
			p = p->next;
		}
		return tmp;
	}
	return l;
}

