/*  Sauvage Tao
	Date: 11/05/11
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
	Data: input (List) list to delete
	Process: travers the list to free each element */
void delete_list(List input)
{
	Elem *current = NULL, *temp = NULL;

	if(input != NULL)
	{
		current = input;
		while(current->next != NULL)
		{
			temp = current;
			current = current->next;
			free(temp);
			temp = NULL;
		}
	}
}

/* Accessor */
/*  Return: (Elem*) head of the list
	Data: input (List) list to process
	Process: process the list to return the first element */
Elem* head(List input)
{
	if(input != NULL)
		return (Elem*)input;
	return input;
}

/*  Return: (void*) data of the head of the list
	Data: input (List) list to process
	Process: process the list to return the data of first element */
void* head_value(List input)
{
	if(input != NULL)
		return input->data;
	return NULL;
}

/*  Return: (Elem*) tail of the list
	Data: input (List) list to process
	Process: travers the list to reach the last element and return it */
Elem* tail(List input)
{
	Elem *current = NULL;

	if(input != NULL)
	{
		current = input;
		while(current->next != NULL)
			current = current->next;
		return current;
	}
	return NULL;
}

/*  Return: (void*) data of tail of the list
	Data: input (List) list to process
	Process: travers the list to reach the last element
	and return its data value */
void* tail_value(List input)
{
	Elem *current = NULL;

	if(input != NULL)
	{
		current = input;
		while(current->next != NULL)
			current = current->next;
		return current->data;
	}
	return NULL;
}

/*  Return: (Bool) true if the list is empty, otherwise false
	Data: input (List) list to test
	Process: test if the list pointer is equal to NULL */
Bool is_empty(List input)
{
	return (input == NULL) ? TRUE : FALSE;
}

/*  Return: (int) the number of element into the list
	Data: input (List) list where elements have to be counted
	Process: travers the list to increment the length and return it */
int length_of(List input)
{
	Elem *current = NULL;
	int length = 0;

	if(input != NULL)
	{
		current = input;
		while(current->next != NULL)
		{
			current = current->next;
			length = length + 1;
		}
		return length + 1;
	}
	return 0;
}

/* Modifiers */
/*  Return: (List) list with one more element
	Data: input (List) list which will receive the new element
		  d (void*) the data of the new element
		  index (int) the index of the new element position
	Process: travers the list to reach the n-th place and add the new element */
List insert_of(List input, void* d, int index)
{
	Elem *current = NULL, *newElem = NULL;
	int i = 0;

	if(input != NULL)
	{
        if(index >= 1)
        {
            index = index - 1;
		    current = input;
		    while(current->next != NULL && i < index)
		    {
		    	current = current->next;
		    	i = i + 1;
	    	}
	    	newElem = (Elem*)calloc(1, sizeof(Elem));
	    	if(newElem != NULL)
	    	{
		      newElem->data = d;
		    	if(i == index)
		    	{
		    		newElem->next = current->next;
                 current->next = newElem;
		    	}
		    	else
		    	{
		    		newElem->next = NULL;
		    		current->next = newElem;
		    	}
		    }
            return input;
        }
        else
            return insert_head(input, d);
	}
	return create_list(NULL);
}

/*  Return: (List) list with one more element at the head of the list
	Data: input (List) list which will receive the new head
		  d (void*) the data of the new element
	Process: add a new element at the head of the list */
List insert_head(List input, void* d)
{
	Elem *current = NULL;

	current = (Elem*) calloc(1, sizeof(Elem));
	if(current != NULL)
	{
		current->next = input;
	    current->data = d;
	}
	return current;
}

/*  Return: (List) list with one more element at the tail of the list
	Data: input (List) list which will receive the new tail
		  d (void*) the data of the new element
	Process: travers the list to reach its end, then add the new element */
List insert_tail(List input, void* d)
{
	Elem *current = NULL, *newElem = NULL;

	if(input == NULL)
		return insert_head(input, d);
	else
	{
		newElem = (Elem*) calloc(1, sizeof(Elem));
		if(newElem != NULL)
		{
			newElem->data = d;
			newElem->next = NULL;
			current = input;
			while(current->next != NULL)
				current = current->next;
			current->next = newElem;
		}
	}
	return input;
}

/*  Return: (List) list with one less element
	Data: input (List) list which will have one less element
		  index (int) the index of the element which will be deleted
	Process: travers the list to reach the n-th element and free it */
List remove_of(List input, int index)
{
	Elem *current = NULL, *previous = NULL, *temp = NULL;
	int i = 0;

	if(input != NULL)
	{
		current = input;
		while(current->next != NULL && i < index)
		{
			current = current->next;
			i = i + 1;
		}
		if(current->next != NULL)
		{
			previous = current;
			current = current->next;
			temp = current;
			current = current->next;
			previous->next = current;
			free(temp);
			temp = NULL;
		}
	}
	return input;
}

/*  Return: (List) list without the head
	Data: input (List) list which will have its head removed
	Process: free the head of the list */
List remove_head(List input)
{
	Elem *current = NULL;

	if(input != NULL)
	{
		current = input;
		current = current->next;
		free(input);
		input = NULL;
		return current;
	}
	return input;
}

/*  Return: (List) list without the tail
	Data: input (List) list which will have its tail removed
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
	Data: input (List) list to reverse
	Process: travers the list to change each next pointer value */
List reverse(List input)
{
	List newList = NULL;
	Elem *current = NULL;

	if(input != NULL)
	{
		newList = input;
		current = input;
		while(current->next != NULL)
		{
			newList = insert_head(current, current->data);
			current = current->next;
		}
		return newList;
	}
	return create_list(NULL);
}

