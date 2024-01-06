#include "monty.h"
#include "monty.h"

int exe_push(stack_t **head, char * number, int linecount)
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
			return(0);
		}
		new_node->n = num;
		new_node->prev = NULL;
		new_node->next = *head;
		if (*head)
			(*head)->prev = new_node;

		*head = new_node;
	}
	return(1);
}

int exe_pall(stack_t **head, char *number, int linecount) 
{	
	(void)linecount;
	(void)number;
	stack_t *current_node = *head;

	printf("EXEPULL: In Line <%i> Printing ALL\n", linecount);
	if (*head == NULL)
		return(1);

	while (current_node != NULL)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
	return(1);
}

 
int exe_pint(stack_t **head, char *number, int linecount)
{
	printf("EXEPINT: In Line <%i> Printing Head Node\n", linecount);
	stack_t *topNode = *head;
	(void)number;
	(void)linecount;
	if (*head == NULL)
	{
		printf("L%d: can't print, stack empty\n", linecount);
		return(0);
	}
	printf("%d\n", topNode->n);
	return(1);
}

int exe_pop(stack_t **head, char *number, int linecount) 
{
	printf("EXEPOP: In Line <%i> Removing Head Node\n", linecount);
	(void)number;

	if (*head == NULL)
	{
		printf("L%d: can't pop, stack empty\n", linecount);
		return(0);
	}
	stack_t *topNode = *head;
	*head = topNode->next;
	if (*head)
	{
		(*head)->prev = NULL;
	}
	free(topNode);
	return(1);
}

int exe_swap(stack_t **head, char *number, int linecount) 
{	
	(void)number;
	printf("EXESWAP: In Line <%i> Swap two top Nodes\n", linecount);
	if (*head == NULL || (*head)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", linecount);
		return(0);
	}

	stack_t *topNode = *head;
	stack_t *nextNode = topNode->next;
	int temp = topNode->n;
	topNode->n = nextNode->n;
	nextNode->n = temp;
	return(1);
}

int exe_add(stack_t **head, char *number, int linecount) 
{
	printf("EXEADD: In Line <%i> Top two elements added into one\n", linecount);
	(void)head;
	(void)number;
	if (*head == NULL || (*head)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", linecount);
		return(0);
	}
	stack_t *topNode = *head;
	stack_t *nextNode = topNode->next;
	nextNode->n += topNode->n;
	*head = nextNode;
	if (*head)
	{
		(*head)->prev = NULL;
	}
	free(topNode);
	return(1);
}

int exe_nop(stack_t **head, char *number, int linecount) 
{
	printf("EXENOP: In Line <%i> NOTHING at all\n", linecount);
	(void)head;
	(void)number;
	(void)linecount;
	return(1);
}

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

