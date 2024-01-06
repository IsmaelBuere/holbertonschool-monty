#include "monty.h"
/**
 * exe_push - Push a new element onto the stack.
 * @head: Double pointer to the head of the stack.
 * @number: String representing the number to be pushed.
 * @linecount: Line number where the operation is called.
 */
void exe_push(stack_t **head, char * number, int linecount, char * command, char ** lines)
{
	int num = 0;
	if (isnumber(number, linecount, command, lines, head) != 0)
	{
		num = atoi(number);

	stack_t *new_node = malloc(sizeof(*new_node));

	if (!new_node)
	{
		printf( "Error: malloc failed\n");
		free(number);
		free(command);
		freedom(lines);
		exit(EXIT_FAILURE);
	}

	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *head;

	if (*head)
		(*head)->prev = new_node;

	*head = new_node;
	}
}