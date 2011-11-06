/*  Ruhier Anthony
	Date : 11/05/2011
	Bubble sort: 
		Sort list and array using the bubble sort method*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "bubble-sort.h"
#include "../../utils/utils.h"
#define L 15

/*  Return: 
	Data: int lenght : the lenght of the array
		   void array : array you want to sort
	Process:  */
void bubblesort_array(int length, int array[])
{

	int i = 0, l = length;
	int tmp = 0;
	Bool changed = TRUE; /* Show if changes have been done on the array */

	do
	{
		changed = FALSE;

		for(i = 0; i < l - 1; i++)
		{
			if(array[i] > array[i+1])
			{
				tmp = array[i];
				array[i] = array[i+1];
				array[i+1] = tmp;
				changed = TRUE;
			}
		}

		l = l - 1;
	} while (changed);


}


