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

    if  (argc != 2) 
            printerror("USAGE: monty file\n");
        
    filename = argv[1];
    file = fopen(filename, "r");

    if (file == NULL)
            printerrorst("Error: Can't open file", argv[1]);

    file_l = filelength(file);
    file_c = malloc(file_l + 1);
    
    if (file_c == NULL)
        printerror("Error: malloc failed\n");

    fread(file_c, 1, file_l, file);
    file_c[file_l] = '\0';
    c1 = filelines(file);
    lines = malloc(c1 * sizeof(char *));
	if (lines == NULL)
	{
		printerror("Error: malloc failed\n");
		free(file_c);
	}
	fclose(file);

    line = strtok(file_c, "\n");
    lines[c2] = strdup(line);
	if (lines[c2] == NULL)
	{
		printerror("Error: strdup failed\n");
		free(file_c);
		free(lines);
	}
	c2++;
    for (c2 = 1 ; c2 < c1 ; c2++)
    {   
        line = strtok(NULL, "\n");
        lines[c2] = strdup(line);
        if (lines[c2] == NULL)
	{
        printerror("Error: strdup failed\n");
	freedom(lines);
	free(file_c);
	}
    }
    free(file_c);
    printf("\n");
    for (c2 = 0 ; c2 < c1 ; c2++)
    {
    	strcopy = strdup(lines[c2]);
    	token1 = malloc(sizeof(char) * 100);
        token2 = malloc(sizeof(char) * 100);
        sscanf(strcopy, "%s %s", token1, token2);
	free(strcopy);
        if (execom(&head, token1, token2, linecount) == 0)
	{
	printf("HERE IS WHERE THE FREE AND EXIT MUST GO\n");
	free(token1);
	free(token2);
	freestack(&head);
	freedom(lines);
	exit(EXIT_FAILURE);
	}
	free(token1);
	free(token2);
        linecount++;
    }
    freedom(lines);
    freestack(&head);
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
    printf("%s\n", string);
    exit(EXIT_FAILURE);
}

void printerrorst (char * string1, char * string2)
{
	printf("%s <%s>\n", string1, string2);
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

