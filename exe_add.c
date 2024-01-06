#include "monty.h"
void add(stack_t **stack, unsigned int data);
{
    stack_t *current_node = *stack;
    unsigned int addition_result;

    (void)data;

    if (current_node == NULL || current_node->next == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", data);
        exit(EXIT_FAILURE);
    }

    addition_result = current_node->n + current_node->next->n;
    current_node->next->n = addition_result;

    pop(stack, data);
}