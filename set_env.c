#include "main.h"

/**
 * set_env - prints enviroment variable
 * @av: argument
 *
 * Return: 1 on success, 0n on failure
 */
int set_env(char **av)
{
	int y = 0;
	(void)(**av);

	while (environ[y])
	{
		write(STDOUT_FILENO, environ[y], strlen(environ[y]));
		write(STDOUT_FILENO, "\n", 1);
		y++;
	}
	return (-1);
}
