#include "main.h"

/**
 * get_strem - reads line from stdin
 *
 * Return: line pointer
 */
char *get_strem(void)
{
	int buf = 1024;
	int k = 0;
	char *input = malloc(sizeof(char) * buf);
	int ch;

	if (input == NULL)
	{
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		ch = getchar();
		if (ch == EOF)
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
		else if (ch == '\n')
		{
			input[k] = '\0';
			return (input);
		}
		else
		{
			input[k] = ch;
		}
		k++;
		if (k >= buf)
		{
			buf += buf;
			input = realloc(input, buf);
			if (input == NULL)
				exit(EXIT_FAILURE);
		}
	}
}
