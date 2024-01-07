#include "monty.h"
/**
 * exe_nop - Does nothing.
 * @head: Double pointer to the top of the stack (unused).
 * @number: Unused parameter (required by function signature).
 * @linecount: Line number where the function is called (unused).
 *
 * Return: Always 1.
 */
int exe_nop(stack_t **head, char *number, int linecount)
{
	(void)head;
	(void)number;
	(void)linecount;
	return (1); }
