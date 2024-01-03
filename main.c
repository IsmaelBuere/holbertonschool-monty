#include "main.h"
/**
 * main - Main entry point of the program.
 * @argc: Number of command-line arguments.
 * @argv: Array of strings containing the command-line arguments.
 *
 * Return: Returns 0 if the execution is successful.
 */
void main (int argc, char * argv[])
{
	void(argc);
	char * filename = NULL;
	int filecode;
    FILE *file = NULL;
    char *file_c;

	filename = argv[1];

	if (filename == NULL)
		printerror("USAGE: monty file\n");

	file = fopen(filename, "r");
    
	if (file == NULL)
		printerror("Error: Can't open file <file>\n");

    file_l = filelength(file);
    file_c = malloc(file_l);

    if (file_c == NULL)
		printerror("Error: malloc failed");
    fread(file_c, 1, file_l, file);

    printf("%s", file_c);
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
    rewind(file) 
    return (file_size);
}
/**
 * printerror - Displays an error message and exits the program.
 * @string: The error message to be displayed.
 *Return: (void)
 */
void printerror (char * string)
{
    printf(string);
    exit(EXIT_FAILURE);
}