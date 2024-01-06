#include "monty.h"
/**
 * exe_pall - Print all elements of the stack.
 * @head: Double pointer to the head of the stack.
 * @number: Unused parameter (required by function signature).
 * @linecount: Unused parameter (required by function signature).
 */
void exe_pall(stack_t **head, char *number, int linecount, char * command, char ** lines)
{
	(void)command;
	(void)linecount;
	(void)number;
	(void)lines;
	
	stack_t *current_node = *head;

	if (*head == NULL)
		return;

	while (current_node != NULL)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}