#include "main.h"

/**
 * str_str - locates a substring.
 * @haystack: finds needle inside here
 * @needle: what we are searching for
 *
 * Return: Always 0
 */

char *str_str(char *haystack, char *needle)
{
	for (; *haystack != '\0'; haystack++)
	{
		char *h = haystack;
		char *n = needle;

		while (*h == *n && *n != '\0')
		{
			h++;
			n++;
		}

		if (*n == '\0')
			return (haystack);
	}

	return (0);
}
