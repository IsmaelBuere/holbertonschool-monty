#include "monty.h"

/**
 * f_push - function that adds node to the stack
 * @head: double head pointer to the stack
 * @cont: line counter
 *
 * Return: nothing
 */
void push(stack_t **head, unsigned int cont)
{
    if (!cmd.arg || !isdigit_str(cmd.arg))
    {
        fprintf(stderr, "L%d: usage: push integer\n", cont);
        fclose(cmd.file);
        free(cmd.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    int n = atoi(cmd.arg);
    if (cmd.changer == 0)
        addnode(head, n);
    else
        addqueue(head, n);
}

/**
 * isdigit_str - check if a string contains only digits
 * @str: input string
 *
 * Return: 1 if all characters are digits, 0 otherwise
 */
int isdigit_str(const char *str)
{
    if (!str || !*str)
        return 0;

    for (; *str; str++)
    {
        if (!isdigit(*str))
            return 0;
    }

    return 1;
}