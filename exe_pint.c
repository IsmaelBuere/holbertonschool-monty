#include "monty.h"
/**
 * exe_pint - Prints the value of the top element in the stack.
 * @head: Double pointer to the top of the stack.
 * @number: Unused parameter (required by function signature).
 * @linecount: Line number where the function is called.
 *
 * Return: 1 if successful, 0 if the stack is empty.
 */
int exe_pint(stack_t **head, char *number, int linecount)
{
	stack_t *topNode = *head;
	(void)number;
	(void)linecount;
	if (*head == NULL)
	{
		printf("L%d: can't print, stack empty\n", linecount);
		return(0);
	}
	printf("%d\n", topNode->n);
	return(1);
}