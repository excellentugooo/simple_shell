#include "main.h"
#include <stdio.h>

/**
 * _atoi - a function that convert a string to an integer
 * @s: string
 *
 * Return: int
 */

int _atoi(char *s)
{
	int a, b, n, lenght, c, digit;

	a = 0;
	b = 0;
	n = 0;
	lenght = 0;
	c = 0;
	digit = 0;

	while (s[lenght] != '\0')
		lenght++;
	while (a < lenght && c == 0)
	{
		if (s[a] == '-')
			++b;

		if (s[a] >= '0' && s[a] <= '9')
		{
			digit = s[a] - '0';
			if (b % 2)
				digit = -digit;
			n = n * 10 + digit;
			c = 1;
			if (s[a + 1] < '0' || s[a + 1] > '9')
				break;
			c = 0;
		}
		a++;
	}
	if (c == 0)
		return (0);
	return (n);
}
