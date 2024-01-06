#include "monty.h"
/**
 * freedom - function to free each element of an array.
 * @array: array to be freed.
 * Return:
 */
void freedom(char **array)
{
	if (array != NULL)
		{
	    int count = 0;
		while (array[count] != NULL)
		{
			++count;
		}
	array = NULL;
	}
}

/**
 * freestring - function
 * @string: string to be freed
 * return: void
 */

void freestring(char * string)
{
if (string != NULL)
	{
	string = NULL;
	}
}