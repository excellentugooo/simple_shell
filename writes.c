#include "main.h"

/**
 * writes - prints string
 *
 * @s: the string to be printed
 * @stream: where to print
 */
void writes(char *s, int stream)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		write(stream, &s[i], 1);
	}
}
