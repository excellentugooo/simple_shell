#include "main.h"

/**
 * writes: prints to either in out or err
 *
 * @str: the string to be printed
 * @stm: where to print to (in out or err)
 *
 * Return: nothing
 */
void writes(char *s, int stream)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		write(stream, &s[i], 1);
	}
}

