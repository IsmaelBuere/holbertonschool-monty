#include"monty.h"
/**
 * freedom - frees an array of char pointers
 * @array: array to free
 * @nol: number of elements to free in the array
 *
 * Return: nothing
 */
void freedom(char **array, int nol)
{
	int c = 0;

	if (array != NULL)
	{
		for (c = 0 ; c < nol ; c++)
		{
			free(array[c]);
		}
		free(array);
	}
}

/**
 * freestack - free a stack and al its nodes
 * @head: head of the stack
 *
 * Return: nothing
 */
void freestack(stack_t **head)
{
	stack_t *current_node = *head;

	while (current_node != NULL)
	{
		stack_t *next_node = current_node->next;

		free(current_node);
		current_node = next_node;
	}
	*head = NULL;
}
