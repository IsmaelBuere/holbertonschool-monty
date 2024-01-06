#include "monty.h"

int main (int argc, char * argv[])
{
	char * filename = NULL, ** lines, *token1, *token2, *strcopy;
	int file_l, c1 = 0, c2 = 0, linecount = 0;
	FILE *file = NULL;
	stack_t *head = NULL;
	char *file_c;

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
	fread(file_c, 1, file_l, file); file_c[file_l] = '\0';
	c1 = filelines(file); lines = malloc(c1 * sizeof(char *));
	if (lines == NULL) {
		printerror("Error: malloc failed\n"); free(file_c);
	}
	fclose(file);
	readlines(lines, file_c, c1);
	free(file_c);
	printf("\n");
	for (c2 = 0 ; c2 < c1 ; c2++) {
		strcopy = strdup(lines[c2]);
		token2 = malloc(sizeof(char) * 100); 
		token1 = malloc(sizeof(char) * 100);
		sscanf(strcopy, "%s %s", token1, token2);
		free(strcopy);
		if (execom(&head, token1, token2, linecount) == 0) {
			free(token1); free(token2);
			freestack(&head); freedom(lines, c1);
			exit(EXIT_FAILURE);
		}
		free(token1); free(token2); linecount++;
	}
	freedom(lines, linecount);
	freestack(&head);
	return (0);
}

void readlines(char ** lines, char * file_c, int c1)
{
	char * line = NULL;
	int c2 = 0;
	line = strtok(file_c, "\n");
	lines[c2] = strdup(line);
	if (lines[c2] == NULL) {
		printerror("Error: strdup failed\n");
		free(file_c);
		free(lines);
	}
	c2++;
	for (c2 = 1 ; c2 < c1 ; c2++) {
		line = strtok(NULL, "\n");
		lines[c2] = strdup(line);
		if (lines[c2] == NULL)  {
			printerror("Error: strdup failed\n");
			freedom(lines, c2);
			free(file_c);
		}
	}
}
