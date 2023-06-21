#include "main.h"

/**
 * str_cat - a  function that concatenates two strings.
 * @dest: input value
 * @src: input value
 *
 * Return: dest
 */
char *str_cat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';
	return (dest);
}
