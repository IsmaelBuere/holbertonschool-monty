#include "monty.h"

void exe_pop(stack_t **stack, unsigned int data);
{
    stack_t *temp_node;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", data);
        exit(EXIT_FAILURE);
    }

    temp_node = *stack;
    *stack = (*stack)->next;

    if (*stack != NULL)
        (*stack)->prev = NULL;

    free(temp_node);
}
