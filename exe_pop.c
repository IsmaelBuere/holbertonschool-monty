#include "monty.h"
/**
 * exe_pop - Removes the top element from the stack.
 * @head: Double pointer to the top of the stack.
 * @number: Unused parameter (required by function signature).
 * @linecount: Line number where the function is called.
 *
 * Return: 1 if successful, 0 if the stack is empty.
 */
int exe_pop(stack_t **head, char *number, int linecount) 
{
	printf("EXEPOP: In Line <%i> Removing Head Node\n", linecount);
	(void)number;

	if (*head == NULL)
	{
		printf("L%d: can't pop, stack empty\n", linecount);
		return(0);
	}
	stack_t *topNode = *head;
	*head = topNode->next;
	if (*head)
	{
		(*head)->prev = NULL;
	}
	free(topNode);
	return(1);
}