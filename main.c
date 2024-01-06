#include "monty.h"

void main(instruction_t opcodes[], stack_t **stack, char *instruction, FILE *file)
{
	char *token = strtok(instruction, " ");
	int index;

	while (token != NULL && strcmp(token, "$") != 0)
	{
		token[strcspn(token, "$")] = '\0';
		index = 0;

		while (opcodes[index].opcode != NULL && strcmp(token, opcodes[index].opcode) != 0)
			index++;

		if (opcodes[index].opcode != NULL)
		{
			if (strcmp(opcodes[index].opcode, "pall") != 0)
				token = strtok(NULL, " ");

			if (token != NULL)
				token[strcspn(token, "$")] = '\0';

			if (strcmp(opcodes[index].opcode, "push") == 0 && atoi(token) == 0
				&& strcmp(token, "0") != 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_count);
				fclose(file);
				free_stack(*stack);
				exit(EXIT_FAILURE);
			}
			else if (token != NULL)
				opcodes[index].f(stack, atoi(token));
			else
				if (strcmp(opcodes[index].opcode, "push") != 0)
					opcodes[index].f(stack, line_count);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_count, token);
			fclose(file);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}

		token = strtok(NULL, " ");
	}
}


int main(int argument_count, char *arguments[])
{
	instruction_t opcodes[] = {{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"nop", nop}, {"swap", swap}, {"add", add}, {NULL, NULL}};
	FILE *file_pointer;
	char line_buffer[256];
	stack_t *stack = NULL;

	if (argument_count != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);

	file_pointer = fopen(arguments[1], "r");
	if (file_pointer == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", arguments[1]), exit(EXIT_FAILURE);

	for (current_line = 1; fgets(line_buffer, sizeof(line_buffer), file_pointer) != NULL; current_line++)
	{
		line_buffer[strcspn(line_buffer, "\n")] = '\0';
		execute_instructions(opcodes, &stack, line_buffer, file_pointer);
	}

	fclose(file_pointer);
	free_stack(stack);
	return (0);
}
