#include"monty.h"

/**
 * execom - executes the command if found
 * @command: command to execute
 * @number: passed as int for possible "push"
 * @linecount: number of line of the file read
 * @head: head of the stack
 * Return: 0 if correct, 1 if not correct
 */

int execom(stack_t **head, char *command, char *number, int linecount)
{
	int counter = 0;
	optionscommand options[] = {{"push", exe_push}, {"pall", exe_pall},
		{"pint", exe_pint}, {"pop", exe_pop}, {"swap", exe_swap},
		{"add", exe_add}, {"nop", exe_nop}, {NULL, NULL}};
	for (counter = 0 ; counter < 7 ; counter++)
	{
		if (strcmp(command, options[counter].name) == 0)
		{
			return (options[counter].f(head, number, linecount));
		}
		else
		{
			if (counter == 6)
			{
				printf("L<%i>: unknown instruction <opcode>\n", linecount);
				return (0);
			}
		}
	}
	exe_pall(head, number, linecount);
	return (0);
}
