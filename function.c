#include "monty.h"

int isnumber(const char *str, int linecount, char * command, char ** lines, stack_t **head )
{
	if (str == NULL || str[0] == '\0')
	{
		printf("L<%i>: usage: push integer\n", linecount);
		free(number);
		free(command);
		freedom(lines);
		freestack(head);
		exit(EXIT_FAILURE);
		return(0);
	}
	while (*str != '\0')
	{
		if ((*str - '0') < 0 || (*str - '0') > 9)
		{
			printf("L<%i>: usage: push integer\n", linecount);
			exit(EXIT_FAILURE);
			return (0);
		}
		str++;
 	}
	return (1);
}

