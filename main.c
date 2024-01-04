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
char * filename = NULL, ** lines;
int file_l, linecount = 1, c1 = 0, c2 = 0;
FILE *file = NULL;

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
    printf("line is :%s\n", line);
    lines[c2] = strdup(line);
    if (lines[c2] == NULL)
        printerror("Error: strdup failed\n");
    printf("line in lines[%i] is: %s\n", c2, lines[c2]);
    c2++;
    printf("number of lines :%i\n", c1);
    while (line != NULL)
    {   
        line = strtok(NULL, "\n");
        lines[c2] = strdup(line);
        printf("line in lines[%i] is: %s\n", c2, lines[c2]);
        linecount++;
        c2++;
    }
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
        line_count++;
        return line_count;
}