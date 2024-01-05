#include "monty.h"
#include "monty.h"

void exe_push(char *number) 
{	
//	int num = 0;i
	printf("INSIDE FUNCTION: exe_push %s\n", number);
	if (isnumber(number) != 0)
	{
//		num = atoi(number);
		printf("INSIDE FUNNCTION: %s IS A NUMBER\n", number);
	}
	else
		printf("NOT A NUMBER\n");
}

void exe_pall(char *number) {
    printf("INSIDE FUNCTION: exe_pall %s\n", number);
}

void exe_pint(char *number) {
    printf("INSIDE FUNCTION: exe_pint %s\n", number);
}

void exe_pop(char *number) {
    printf("INSIDE FUNCTION: exe_pop %s\n", number);
}

void exe_swap(char *number) {
    printf("INSIDE FUNCTION: exe_swap %s\n", number);
}

void exe_add(char *number) {
    printf("INSIDE FUNCTION: exe_add %s\n", number);
}

void exe_nop(char *number) {
    printf("INSIDE FUNCTION: exe_nop %s\n", number);
}

int isnumber(const char *str) 
{
	if (str == NULL)
	{
		printerror("L<line_number>: usage: push integer\n");
		return(0);
	}
	while (*str != '\0') 
	{
		if (!isdigit(*str))
		{
		
			return (0);
		}
		str++;
 	}
	return (1);
}
