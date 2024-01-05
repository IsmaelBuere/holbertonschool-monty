#include "monty.h"
/**
 * exe_swap - Swap the top two elements of the stack.
 * @head: Double pointer to the head of the stack.
 * @number: Unused parameter (required by function signature).
 * @linecount: Line number where the operation is called.
 */
void exe_swap(stack_t **head, char *number, int linecount, char * command, char ** lines)
{
	(void)number;

	if (*head == NULL || (*head)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", linecount);
		free(number);
		free(command);
		freedom(lines);
		freestack(head);
		exit(EXIT_FAILURE);
	}

	stack_t *topNode = *head;
	stack_t *nextNode = topNode->next;

	int temp = topNode->n;
	topNode->n = nextNode->n;
	nextNode->n = temp;
}