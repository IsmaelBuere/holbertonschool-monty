#include "monty.h"
/**
 * exe_pop - Remove the top element from the stack.
 * @head: Double pointer to the head of the stack.
 * @number: Unused parameter (required by function signature).
 */
void exe_pop(stack_t **head, char *number, int linecount, char * command, char ** lines)
{
	(void)number;

	if (*head == NULL)
	{
		printf("L%d: can't pop, stack empty\n", linecount);
		free(command);
		freedom(lines);
		free(number);
		freestack(head);
		exit(EXIT_FAILURE);
	}

	stack_t *topNode = *head;
	*head = topNode->next;

	if (*head)
	{
		(*head)->prev = NULL;
	}

	free(topNode);
}