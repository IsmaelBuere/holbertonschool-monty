#include "monty.h"

void exe_pall(stack_t **stack, unsigned int data);
{
    stack_t *current_node = *head;

    (void)data;

    if (*head == NULL)
        return;

    while (current_node != NULL)
    {
        printf("%d\n", current_node->n);
        current_node = current_node->next;
    }
}
