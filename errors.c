#include"monty.h"

/**
 * printerror - Displays an error message and exits the program.
 * @string: The error message to be displayed.
 *Return: (void)
 */
void printerror (char * string)
{
	printf("%s\n", string);
	exit(EXIT_FAILURE);
}

void printerrorst (char * string1, char * string2)
{
	printf("%s <%s>\n", string1, string2);
}