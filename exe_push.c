#include "monty.h"
/**
 * exe_push - Adds a new node with a given number to the stack.
 * @head: Double pointer to the top of the stack.
 * @number: String representing the number to be added.
 * @linecount: Line number where the function is called.
 *
 * Return: 1 if successful, 0 if memory allocation fails or
 * if 'number' is not a valid integer.
 */
int exe_push(stack_t **head, char *number, int linecount)
{
	int num = 0;

	if (isnumber(number, linecount) != 0)
	{
		num = atoi(number);
		stack_t *new_node = malloc(sizeof(*new_node));

		if (!new_node)
		{
			fprintf(stderr, "Error: malloc failed\n");
			return (0);
		}
		new_node->n = num;
		new_node->prev = NULL;
		new_node->next = *head;
		if (*head)
			(*head)->prev = new_node;

		*head = new_node;
	}
	return (1); }
