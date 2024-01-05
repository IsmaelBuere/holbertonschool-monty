#include "monty.h"
#include "monty.h"

void exe_push(char *number, int linecount) 
{	
	
	printf("INSIDE FUNCTION: exe_push %s\n", number);
	if (isnumber(number, linecount) != 0)
	{
		
		printf("INSIDE FUNNCTION: %s IS A NUMBER\n", number);
	}
	else
		printf("NOT A NUMBER\n");
}

void exe_pall(char *number, int linecount) {

	printf("INSIDE FUNCTION: exe_push %s\n", number);
	if (isnumber(number, linecount) != 0)
	{
		
		printf("INSIDE FUNNCTION: %s IS A NUMBER\n", number);
	}
	else
		printf("NOT A NUMBER\n");

}

void exe_pint(char *number, int linecount) {
printf("INSIDE FUNCTION: exe_push %s\n", number);
	if (isnumber(number, linecount) != 0)
	{
			printf("INSIDE FUNNCTION: %s IS A NUMBER\n", number);
	}
	else
		printf("NOT A NUMBER\n");
}

void exe_pop(char *number, int linecount) {
	
	printf("INSIDE FUNCTION: exe_push %s\n", number);
	if (isnumber(number, linecount) != 0)
	{
	
		printf("INSIDE FUNNCTION: %s IS A NUMBER\n", number);
	}
	else
		printf("NOT A NUMBER\n");
}

void exe_swap(char *number, int linecount) {

	printf("INSIDE FUNCTION: exe_push %s\n", number);
	if (isnumber(number, linecount) != 0)
	{
		
		printf("INSIDE FUNNCTION: %s IS A NUMBER\n", number);
	}
	else
		printf("NOT A NUMBER\n");
}

void exe_add(char *number, int linecount) {
	
	printf("INSIDE FUNCTION: exe_push %s\n", number);
	if (isnumber(number, linecount) != 0)
	{
	
		printf("INSIDE FUNNCTION: %s IS A NUMBER\n", number);
	}
	else
		printf("NOT A NUMBER\n");
}

void exe_nop(char *number, int linecount) {

	printf("INSIDE FUNCTION: exe_push %s\n", number);
	if (isnumber(number, linecount) != 0)
	{
	
		printf("INSIDE FUNNCTION: %s IS A NUMBER\n", number);
	}
	else
		printf("NOT A NUMBER\n");
}

int isnumber(const char *str, int linecount) 
{
	if (str == NULL || str[0] == '\0')
	{
		printf("L<%i>: usage: push integer\n", linecount);
		error(EXIT_FAILURE);
		return(0);
	}
	while (*str != '\0') 
	{
		if ((*str - '0') < 0 || (*str - '0') > 9)
		{
		
			return (0);
		}
		str++;
 	}
	return (1);
}
