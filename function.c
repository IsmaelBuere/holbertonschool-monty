#include "monty.h"
/**
 * isnumber - Checks if a string represents a valid integer.
 * @str: String to be checked.
 * @linecount: Line number where the function is called.
 *
 * Return: 1 if the string is a valid integer, 0 otherwise.
 */
int isnumber(const char *str, int linecount)
{
	if (str == NULL || str[0] == '\0')
	{
		printf("L<%i>: usage: push integer\n", linecount);
		return (0);
	}
	while (*str != '\0')
	{
		if ((*str - '0') < 0 || (*str - '0') > 9)
		{
			printf("L<%i>: usage: push integer\n", linecount);
			return (0);
		}
		str++;
 	}
	return(1);
}

