#include "main.h"
/**
 * str_len - returns the length of a string
 * @s: string
 * Return: length
 */
int str_len(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}

	return (length);
}
