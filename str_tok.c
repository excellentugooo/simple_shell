#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _strtoky - function that cuts a string into tokens depending on the delimiters
 * @s: string to cut into parts
 * @d: delimiters
 * Return: first partition
 */
char *str_tok(char *s, char *d)
{
	static char *ultimo;
	int i = 0, j = 0;

	if (!s)
		s = ultimo;
	while (s[i] != '\0')
	{
		int cont = 0;
		while (d[cont] != '\0')
		{
			if (s[i] == d[cont])
				break;
			cont++;
		}

		if (d[cont] == '\0' && s[i + 1] == '\0')
		{
			ultimo = s + i + 1;
			s[i + 1] = '\0';
			s = s + j;
			return (s);
		}
		else if (d[cont] == '\0' && d[i + 1] == '\0')
			i++;
		else if (d[cont] == '\0' && d[i + 1] != '\0')
		{
			ultimo = s + i + 1;
			s[i + 1] = '\0';
			ultimo++;
			s = s + j;
			return (s);
		}
		else if (d[cont] != '\0')
			i++;
		j++;
	}
	return (NULL);
}

/*int main(void)
{
	char input[] = "Hello, world! This is a sample string.";
	char delimiters[] = " ,.!";  // Delimiters: space, comma, period, exclamation mark

	char *token = _strtoky(input, delimiters);
	while (token != NULL)
	{
		printf("%s\n", token);
		token = _strtoky(NULL, delimiters);
	}

	return 0;
}
*/
