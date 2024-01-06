#include "monty.h"

void exe_swap(stack_t **stack, unsigned int data);
{
    stack_t *temp_node;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", data);
        exit(EXIT_FAILURE);
    }

    temp_node = (*stack)->next;
    (*stack)->next = temp_node->next;
    temp_node->prev = NULL;

    if (temp_node->next != NULL)
        temp_node->next->prev = *stack;

    temp_node->next = *stack;
    (*stack)->prev = temp_node;
    *stack = temp_node;
}