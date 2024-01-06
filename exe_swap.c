#include "monty.h"
/**
 * exe_swap - Swaps the top two elements of the stack.
 * @head: Double pointer to the top of the stack.
 * @number: Unused parameter (required by function signature).
 * @linecount: Line number where the function is called.
 *
 * Return: 1 if successful, 0 if the stack is too short.
 */
int exe_swap(stack_t **head, char *number, int linecount) 
{	
	(void)number;
	printf("EXESWAP: In Line <%i> Swap two top Nodes\n", linecount);
	if (*head == NULL || (*head)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", linecount);
		return(0);
	}

	stack_t *topNode = *head;
	stack_t *nextNode = topNode->next;
	int temp = topNode->n;
	topNode->n = nextNode->n;
	nextNode->n = temp;
	return(1);
}