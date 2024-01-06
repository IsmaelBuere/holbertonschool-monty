#include "monty.h"
/**
 * exe_pall - Prints all elements in the stack.
 * @head: Double pointer to the top of the stack.
 * @number: Unused parameter (required by function signature).
 * @linecount: Line number where the function is called (unused).
 *
 * Return: Always 1.
 */
int exe_pall(stack_t **head, char *number, int linecount) 
{	
	(void)linecount;
	(void)number;
	stack_t *current_node = *head;

	printf("EXEPULL: In Line <%i> Printing ALL\n", linecount);
	if (*head == NULL)
		return(1);

	while (current_node != NULL)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
	return(1);
}