#include "monty.h"
/**
 * exe_add - Adds the top two elements of the stack.
 * @head: Double pointer to the top of the stack.
 * @number: Unused parameter (required by function signature).
 * @linecount: Line number where the function is called.
 *
 * Return: 1 if successful, 0 if the stack is too short.
 */
int exe_add(stack_t **head, char *number, int linecount)
{
	(void)head;
	(void)number;
	(void)linecount;
	if (*head == NULL || (*head)->next == NULL)
	{
		return (0);
	}
	stack_t *topNode = *head;
	stack_t *nextNode = topNode->next;

	nextNode->n += topNode->n;
	*head = nextNode;
	if (*head)
	{
		(*head)->prev = NULL; }
	free(topNode);
	return (1); }
