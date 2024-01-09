#include"monty.h"
/**
 * exe_pop - Removes the top element from the stack
 * @head: double pointer to the top of the stack
 * @number: unused parameter in this case
 * @linecount: line of the file read containing the command
 *
 * Return: 1 if succesful, 0 if the stack is empty
 *
 */

int exe_pop(stack_t **head, char *number, int linecount)
{
	(void)number;

	if (*head == NULL)
	{
		printf("L%i: can't pop, stack empty\n", linecount);
		return (0);
	}
	stack_t *topNode = *head;
	*head = topNode->next;
	if (*head)
	{
		(*head)->prev = NULL;
	}
	free(topNode);
	return (1); }
