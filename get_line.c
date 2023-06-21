#include "main.h"

/**
* get_line - reads the input from stdin.
* @n: size of buffer
* @lineptr: stores the address of buffer.
* Return: number of characters read.
*/
ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
	if (lineptr == NULL && n == 0)
	{
		n = str_len(lineptr);
		lineptr = malloc(sizeof(char *) * n);
	}
	else
	{
		n = str_len(lineptr);
		lineptr = realloc(sizeof(char *) * n);
	}
