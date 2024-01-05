#include "monty.h"

/**
 * exe_push - Execute the push opcode.
 * @number: A pointer to a string containing the integer argument for push.
 * Return: (void)
 */
void exe_push(char *number)
{
    int value;

    if (!number || !is_integer(number))
    {
        fprintf(stderr, "L<line_number>: usage: push integer\n");
        exit(EXIT_FAILURE);
    }

    value = atoi(number);
    push(value);
}

/**
 * exe_pall - Execute the pall opcode.
 * @number: A pointer to a string (not used for pall).
 * Return: (void)
 */
void exe_pall(char *number)
{
    (void)number;

    pall();
}
/**
 * push - Add a value to the stack.
 * @value: The value to be pushed onto the stack.
 * Return: (void)
 */
void push(int value)
{
}

/**
 * pall - Print all values on the stack.
 * Return: (void)
 */
void pall()
{
}
