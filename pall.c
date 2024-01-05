#include "monty.h"

#define STACK_SIZE 100

int stack[STACK_SIZE];
int top = -1;

void push(int value) {
    if (top == STACK_SIZE - 1) {
        fprintf(stderr, "L%d: Error: stack overflow\n", __LINE__);
        exit(EXIT_FAILURE);
    }

    stack[++top] = value;
}

void exe_pall() {
    int i;
    for (i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}