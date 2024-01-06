#include "monty.h"

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		cleanup(NULL, NULL, *stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

void pint(stack_t **h, unsigned int a)
{
	stack_t *current = *h;

	if (*h == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_count);
		exit(EXIT_FAILURE);
	}
	(void) a;
	printf("%d\n", current->n);
}