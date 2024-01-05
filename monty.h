#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct optcom
{
	char * name;
	void (*f)(stack_t **head, char * number, int linecount);
} optionscommand;

void printerror (char * string);
int filelength(FILE *file);
int filelines(FILE *file);
void execom(stack_t **head, char * command, char * number, int linecount);
void push(stack_t **head, char * number, int linecount);
void exe_nop(stack_t **head, char * number, int linecount);
void exe_add(stack_t **head, char * number, int linecount);
void exe_swap(stack_t **head, char * number, int linecount);
void exe_pop(stack_t **head, char * number, int linecount);
void exe_pint(stack_t **head, char * number, int linecount);
void exe_pall(stack_t **head, char * number, int linecount);
int isnumber(const char *str, int linecount);
int isdigit_str(stack_t **head, const char *str);

#endif