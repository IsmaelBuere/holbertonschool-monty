#include "monty.h"
/**
 * exe_pint - Print the value at the top of the stack.
 * @head: Double pointer to the head of the stack.
 * @number: Unused parameter (required by function signature).
 * @linecount: Line number where the operation is called.
 */
void exe_pint(stack_t **head, char *number, int linecount, char * command, char ** lines)
{
	stack_t *topNode = *head;
    (void)lines;
    (void)command;
	(void)number;
	(void)linecount;
	if (*head == NULL)
	{
		printf("L%d: can't print, stack empty\n", linecount);
		free(&number);
        freestack(head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", topNode->n);
}