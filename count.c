#include"monty.h"

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