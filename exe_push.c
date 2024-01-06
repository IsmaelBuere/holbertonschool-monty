void exe_push(stack_t **stack, unsigned int data)
{
    stack_t *new_element = malloc(sizeof(stack_t));

    if (new_element == NULL)
    {
        free(new_element);
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_element->n = data;
    new_element->prev = *stack;
    new_element->next = NULL;

    if (*stack != NULL)
        (*stack)->next = new_element;

    *stack = new_element;
}
