#include "monty.h"
#include "monty.h"

void exe_push(stack_t **head, char * number, int linecount)
{   
	printf("EXEPUSH: In Line <%i> Number is <%s>\n", linecount, number);
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
	(void)number;
    stack_t *current_node = *head;

    printf("EXEPULL: In Line <%i> Printing ALL\n", linecount);
    (void) linecount;

    if (*head == NULL)
        return;

    while (current_node != NULL)
    {
        printf("%d\n", current_node->n);
        current_node = current_node->next;
    }
}

 
void exe_pint(stack_t **head, char *number, int linecount)
{
	printf("EXEPINT: In Line <%i> Printing Head Node\n", linecount);
    stack_t *topNode = *head;
	(void)number;
	(void)linecount;
    if (*head == NULL)
    {
        printf("L%d: can't print, stack empty\n", linecount);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", topNode->n);
}

void exe_pop(stack_t **head, char *number, int linecount) 
{
	printf("EXEPOP: In Line <%i> Removing Head Node\n", linecount);
	(void)head;
	if (isnumber(number, linecount) != 0)
	{
	
	}
}

void exe_swap(stack_t **head, char *number, int linecount) 
{
	printf("EXESWAP: In Line <%i> Swap two top Nodes\n", linecount);
	(void)head;
	if (isnumber(number, linecount) != 0)
	{
		
	}
}

void exe_add(stack_t **head, char *number, int linecount) 
{
	printf("EXEADD: In Line <%i> Top two elements added into one\n", linecount);
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

