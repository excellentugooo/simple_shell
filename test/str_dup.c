#include "main.h"
#include <stdlib.h>

/**
 * str_dup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: string
 *
 * Return: dup on success and null on faillure
 */

char *str_dup(char *str)
{
	char *dup;
	int a, b;

	if (str == NULL)
	{
		return (NULL);
	}

	a = 0;
	while (str[a] != '\0')
	{
		a++;
	}

	dup = malloc((a + 1) * sizeof(char));

	if (dup == NULL)
	{
		return (NULL);
	}
	for (b = 0; str[b]; b++)
	{
		dup[b] = str[b];
	}

	return (dup);
}
