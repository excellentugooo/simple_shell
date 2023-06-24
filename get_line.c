#include "main.h"

/**
* get_line - reads the input from stdin.
* @n: size of buffer
* @lineptr: stores the address of buffer.
* Return: number of characters read.
*/
/**ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
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
	}*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
    size_t pos = 0;
    int eof_reached = 0;
    char c;
    char *temp;
    ssize_t bytes_read;

    if (*lineptr == NULL && *n == 0)
    {
        *n = 1; /* Initialize the line length to 0*/
        *lineptr = malloc(sizeof(char) * (*n + 1)); /* Allocate memory for an empty string*/
        if (*lineptr == NULL)
        {
            return -1; /* Memory allocation failed*/
        }
    }


    while (!eof_reached)
    {
        bytes_read = read(fileno(stream), &c, 1);
        if (bytes_read <= 0)
        {
            break; /* End the loop if read encounters an error or EOF*/
        }

        if (pos >= (*n -1))
        {
            *n *= 2; /* Double the allocated memory size*/
            temp = realloc(*lineptr, sizeof(char) * (*n + 1));
            if (temp == NULL)
            {
                return -1; /* Memory reallocation failed*/
            }
            *lineptr = temp;
        }

        (*lineptr)[pos++] = c;

        if (c == '\n')
        {
            break; /* End the loop when encountering a newline character*/
        }
    }

    if (pos == 0)
    {
        return -1; /* No characters read (EOF reached or error occurred)*/
    }

    (*lineptr)[pos] = '\0'; /* Add null terminator*/

    return pos; /* Return the number of characters read (excluding null terminator)*/
}

/*int main()
{
    char *line = NULL;
    size_t buffer_size = 0;

    printf("Enter a line of text: ");
    fflush(stdout);

    ssize_t line_length = get_line(&line, &buffer_size, stdin);

    if (line_length != -1)
    {
        printf("You entered: %s\n", line);
    }
    else
    {
        printf("An error occurred or end-of-file reached.\n");
    }

    free(line);

    return 0;
}*/
