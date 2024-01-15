#include"monty.h"

/**
 * execom - executes the command
 * @command: command to execute
 * @number: passed as int for possible "push"
 * @linecount: number of line of the file read
 * @head: head of the stack
 * Return: 0 if correct, 1 if not correct
 */

int execom(stack_t **head, char *command, char *number, int linecount)
{
	int counter = 0;
	instruction_t options[] = {{"push", exe_push}, {"pall", exe_pall},
		{"pint", exe_pint}, {"pop", exe_pop}, {"swap", exe_swap},
		{"add", exe_add}, {"nop", exe_nop}, {NULL, NULL}};

	for (counter = 0 ; options[counter].opcode != NULL ; counter++)
	{
		if (strcmp(command, options[counter].opcode) == 0)
		{
			return (options[counter].f(head, number, linecount));
		}
	}
	fprintf(stderr, "L%i: unknown instruction %s\n", linecount, command);
	return (0);
}
