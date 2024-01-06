#include "monty.h"

int exe_pint(stack_t **head, char *number, int linecount)
{
	printf("EXEPINT: In Line <%i> Printing Head Node\n", linecount);
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