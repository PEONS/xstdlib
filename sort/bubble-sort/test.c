/*  Ruhier Anthony
	Date : 11/05/2011
	Bubble Sort Test
		Test file testing bublesort */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "bubble-sort.h"
#include "../../utils/utils.h"

#define L 15

int main()
{

	int i = 0, val = 0;
	int array[L] = {0};	

	srand(time(NULL));

	for (i = 0; i < L ; i++)
	{		
		val = (rand() % 30) + 1;
		array[i] = val;

	}

	bubblesort_array(L, array);

	printf("\n\n");

	for (i = 0; i < L; i++)
	{
		
		printf(" %.0d ", array[i]);

	}

	return 0;

}

