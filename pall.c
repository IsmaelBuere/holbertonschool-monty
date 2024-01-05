#include "monty.h"

void exe_push(char *number) {
    if (!number || !isdigit(*number)) {
        fprintf(stderr, "L%d: usage: push integer\n", __LINE__);
        exit(EXIT_FAILURE);
    }
    push(atoi(number));
}

void exe_pall(char *number) {
    (void)number; // Unused parameter
    pall();
}