#include "main.h"

/**
 * get_env - gets an environment variable
 * @enviv: environment variable
 *
 * Return: envronment variable
 */

extern char **environ;
char *get_env(char *enviv)
{
	int i = 0;
	int lenght = str_len(enviv);
	char *check;

	while (environ[i] != NULL)
	{
		check = strstr(environ[i], enviv);
		if (check != NULL)
		{
			return (check + lenght + 1);
		}
		i++;
	}
	return (NULL);
}
