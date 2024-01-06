#include"monty.h"

int execom(stack_t **head, char * command, char * number, int linecount)
{
	int counter = 0;
	optionscommand options[] = {{"push", exe_push}, {"pall", exe_pall},
		{"pint", exe_pint}, {"pop", exe_pop}, {"swap", exe_swap},
		{"add", exe_add}, {"nop", exe_nop}, {NULL, NULL}};
	for (counter = 0 ; counter < 7 ; counter++)
	{
		if (strcmp(command, options[counter].name) == 0)
		{
			return(options[counter].f(head, number, linecount));
			break;
		}
		else
		{
			if (counter == 6)
			{
				printf("L<%i>: unknown instruction <opcode>\n", linecount);
				return(0);
			}
		}
	}
	exe_pall(head, number, linecount);
	return(0);
}
