#include "monty.h"
#include "monty.h"

void exe_push(char *number, int linecount) 
{	
//	int num = 0;i
	printf("INSIDE FUNCTION: exe_push %s\n", number);
	if (isnumber(number, linecount) != 0)
	{
//		num = atoi(number);
		printf("INSIDE FUNNCTION: %s IS A NUMBER\n", number);
	}
	else
		printf("NOT A NUMBER\n");
}

void exe_pall(char *number, int linecount) {
	void(linecount);
    printf("INSIDE FUNCTION: exe_pall %s\n", number);
}

void exe_pint(char *number, int linecount) {
	void(linecount);
    printf("INSIDE FUNCTION: exe_pint %s\n", number);
}

void exe_pop(char *number, int linecount) {
	void(linecount);
    printf("INSIDE FUNCTION: exe_pop %s\n", number);
}

void exe_swap(char *number, int linecount) {
	void(linecount);
    printf("INSIDE FUNCTION: exe_swap %s\n", number);
}

void exe_add(char *number, int linecount) {
	void(linecount);
    printf("INSIDE FUNCTION: exe_add %s\n", number);
}

void exe_nop(char *number, int linecount) {
	void(linecount);
    printf("INSIDE FUNCTION: exe_nop %s\n", number);
}

int isnumber(const char *str, int linecount) 
{
	if (str == NULL || str[0] == '\0')
	{
		printerror("L<%i>: usage: push integer\n", linecount);
		return(0);
	}
	while (*str != '\0') 
	{
		if if ((*str - '0') < 0 || (*str - '0') > 9)
		{
		
			return (0);
		}
		str++;
 	}
	return (1);
}
