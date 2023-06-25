#include "main.h"

/**
 * str_tok - function that cut a string into tokens depending of the delimit
 * @s: string to cut in parts
 * @d: delzlimiters
 * Return: first partition
 */
char *str_tok(char *s, char *d)
{
	static char *token;
	int i = 0, j = 0;

	if (!s)
		s = token;
	while (s[i] != '\0')
	{
		if (srchdelim(d, s[i]) == 0 && s[i + 1] == '\0')
		{
			token = s + i + 1;
			*token = '\0';
			s = s + j;
			return (s);
		}
		else if (srchdelim(d, s[i]) == 0 && srchdelim(d, s[i + 1]) == 0)
			i++;
		else if (srchdelim(d, s[i]) == 0 && srchdelim(d, s[i + 1]) == 1)
		{
			token = s + i + 1;
			*token = '\0';
			token++;
			s = s + j;
			return (s);
		}
		else if (srchdelim(d, s[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return (NULL);
}
