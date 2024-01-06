#include"monty.h"

void freedom(char **array)
{
	if (array != NULL)
	{	
		int count = 0;
		while (array[count] != NULL) 
		{	
			free(array[count]);
			array[count] = NULL;
			++count;
		}
		free(array);
		array = NULL;
	}
}

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
