#include "monty.h"
/**
 * exe_add - Add the top two elements of the stack.
 * @head: Double pointer to the head of the stack.
 * @number: Unused parameter (required by function signature).
 * @linecount: Line number where the operation is called.
 * Return: (void)
 */

void exe_add(stack_t **head, char *number, int linecount, char * command, char ** lines)
{
	(void)head;
	(void)number;
	if (*head == NULL || (*head)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", linecount);
        free(number);
        free(command);
        freedom(lines);
        freestack(&head);
    	exit(EXIT_FAILURE);
	}

	stack_t *topNode = *head;
	stack_t *nextNode = topNode->next;

	nextNode->n += topNode->n;

	   *head = nextNode;
	if (*head)
	{
		(*head)->prev = NULL;
	}

	free(topNode);
}