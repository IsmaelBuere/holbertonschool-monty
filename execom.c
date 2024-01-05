#include "monty.h"
/**
 * filelines - Count the number of lines in a given file.
 * @file: Pointer to the FILE structure representing the open file.
 * Return: The number of lines in the file.
 */
int filelines(FILE *file)
{
        int ch;
        int line_count = 0;

        rewind(file);
        while ((ch = fgetc(file)) != EOF)
        {
            if (ch == '\n')
            {
                line_count++;
            }
        }
        return line_count;
}
/**
 * execom - Execute a command based on the provided command and number.
 * @command: A pointer to a string representing the command to be executed.
 * @number: A pointer to a string containing additional information for the command.
 * Return: (void)
 */

void execom(stack_t **head, char * command, char * number, int linecount)
{     
        int counter = 0;
        optionscommand options[] = {{"push", exe_push}, {"pall", exe_pall},
		{"pint", exe_pint}, {"pop", exe_pop}, {"swap", exe_swap},
		{"add", exe_add}, {"nop", exe_nop}, {NULL, NULL}};
           
    for (counter = 0 ; counter < 7 ; counter++)
    {
        if (strcmp(command, options[counter].name) == 0)
    	{
		    options[counter].f(head, number, linecount);
		    break;
	    }
        else
        {   
            if (counter == 6)
            {
                printf("L<%i>: unknown instruction <%s>\n", linecount, command);
                exit(EXIT_FAILURE);
            }
        }
    }
}

