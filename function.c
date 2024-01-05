#include "monty.h"
#include "monty.h"

void exe_push(stack_t **head, char * number, int linecount)
{   
    int num = 0;
    if (isnumber(number, linecount) != 0)
	{
        num = atoi(number);

    stack_t *new_node = malloc(sizeof(*new_node));

    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = num;
    new_node->prev = NULL;
    new_node->next = *head;

    if (*head)
        (*head)->prev = new_node;

    *head = new_node;
    }
}

void exe_pall(stack_t **head, char *number, int linecount) 
{	
	(void)head;
	if (isnumber(number, linecount) != 0)
	{
			
	}
}

void exe_pint(stack_t **head, char *number, int linecount) 
{
	(void)head;
	if (isnumber(number, linecount) != 0)
	{

	}
}

void exe_pop(stack_t **head, char *number, int linecount) 
{
	(void)head;
	if (isnumber(number, linecount) != 0)
	{
	
	}
}

void exe_swap(stack_t **head, char *number, int linecount) 
{
	(void)head;
	if (isnumber(number, linecount) != 0)
	{
		
	}
}

void exe_add(stack_t **head, char *number, int linecount) 
{
	(void)head;
	if (isnumber(number, linecount) != 0)
	{
	}
}

void exe_nop(stack_t **head, char *number, int linecount) 
{
	(void)head;
	if (isnumber(number, linecount) != 0)
	{

	}
}

int isnumber(const char *str, int linecount) 
{
	if (str == NULL || str[0] == '\0')
	{
		printf("L<%i>: usage: push integer\n", linecount);
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

