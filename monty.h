#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>


typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int data);
} instruction_t;

void add(stack_t **stack, unsigned int data);
void free_stack(stack_t **stack);
void main(instruction_t opcodes[], stack_t **stack, char *instruction, FILE *file);
void exe_nop(stack_t **stack, unsigned int data);
void exe_push(stack_t **stack, unsigned int data);
void exe_pall(stack_t **stack, unsigned int data);
void exe_pint(stack_t **stack, unsigned int data);
void exe_pop(stack_t **stack, unsigned int data);
void exe_sub(stack_t **stack, unsigned int data);
void exe_swap(stack_t **stack, unsigned int data);

#endif