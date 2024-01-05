#include "monty.h"
/**
 * main - Main entry point of the program.
 * @argc: Number of command-line arguments.
 * @argv: Array of strings containing the command-line arguments.
 *
 * Return: Returns 0 if the execution is successful.
 */
int main (int argc, char * argv[])
{
char * filename = NULL, ** lines, *token1, *token2, *strcopy;
int file_l, c1 = 0, c2 = 0, linecount = 0;
FILE *file = NULL;
stack_t *head = NULL; 

char *file_c, *line = NULL;

    if (argc < 2) 
            printerror("USAGE: monty file\n");
        
    filename = argv[1];
    file = fopen(filename, "r");

    if (file == NULL)
            printerror("Error: Can't open file <file>\n");

    file_l = filelength(file);
    file_c = malloc(file_l + 1);
    
    if (file_c == NULL)
        printerror("Error: malloc failed\n");

    fread(file_c, 1, file_l, file);
    file_c[file_l] = '\0';
    c1 = filelines(file);
    lines = malloc(c1 * sizeof(char *));
    if (lines == NULL)
        printerror("Error: malloc failed\n");
    fclose(file);

    line = strtok(file_c, "\n");
    lines[c2] = strdup(line);
    if (lines[c2] == NULL)
        printerror("Error: strdup failed\n");
    c2++;
    for (c2 = 1 ; c2 < c1 ; c2++)
    {   
        line = strtok(NULL, "\n");
        lines[c2] = strdup(line);
        if (lines[c2] == NULL)
        printerror("Error: strdupfailed\n");
    }
    printf("\n");
    for (c2 = 0 ; c2 < c1 ; c2++)
    {
    	strcopy = strdup(lines[c2]);
    	token1 = malloc(sizeof(char) * 100);
        token2 = malloc(sizeof(char) * 100);
        sscanf(strcopy, "%s %s", token1, token2);
	//	printf("token1 is %s\n", token1);
	//	printf("token2 is %s\n", token2);
	//	printf("BEFORE EXECOM: token1 = %s and token 2 = %s\n", token1, token2);
		free(strcopy);
        execom(&head, token1, token2, linecount);
	    free(token1);
		free(token2);
        linecount++;
    }
    printf("\n");

return (0);
}


/**
 * filelength - Calculates the size of the file.
 * @file: Pointer to the FILE structure representing the file.
 *
 * Return: The size of the file in bytes.
 */
int filelength(FILE *file)
{
    int file_size;
    
    fseek(file, 0, SEEK_END); 
    file_size = ftell(file); 
    rewind(file);
    return (file_size);
}
/**
 * printerror - Displays an error message and exits the program.
 * @string: The error message to be displayed.
 *Return: (void)
 */
void printerror (char * string)
{
    printf("%s", string);
    exit(EXIT_FAILURE);
}

int filelines(FILE *file)
{
        int ch;
        int line_count = 0;

        rewind(file);
        while ((ch = fgetc(file)) != EOF)
        {
            if (ch == '\n')
            {
                line_count++;
            }
        }
        return line_count;
}
/**
 * execom - Execute a command based on the provided command and number.
 * @command: A pointer to a string representing the command to be executed.
 * @number: A pointer to a string containing additional information for the command.
 * Return: (void)
 */

void execom(stack_t **head, char * command, char * number, int linecount)
{     
     printf("INSIDE EXECOM: command is %s and number is %s \n", command, number);	
        int counter = 0;
        optionscommand options[] = {{"push", exe_push}, {"pall", exe_pall},
		{"pint", exe_pint}, {"pop", exe_pop}, {"swap", exe_swap},
		{"add", exe_add}, {"nop", exe_nop}, {NULL, NULL}};
           
    for (counter = 0 ; counter < 7 ; counter++)
    {
        if (strcmp(command, options[counter].name) == 0)
    	{
		    options[counter].f(head, number, linecount);
		    break;
	    }
        else
        {   
            if (counter == 6)
                printf("L<%i>: unknown instruction <opcode>", linecount);
        }
    }
}

