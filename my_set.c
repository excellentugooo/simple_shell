#include "main.h"

/**
 * my_setenv - initializes a new environment variable
 * @av: arguments.
 *
 * Return: 0 on success, -1 on failure.
 */

int my_setenv(char **av)
{
	if (av[1] == NULL || av[2] == NULL)
	{
		perror("setenv: Invalid arguments");
		return (-1);
	}

	if (setenv(av[1], av[2], 1) != 0)
	{
		perror("setenv failed");
		return (-1);
	}

	return (0);
}

/**
 * my_unsetenv - removes an environment variable
 * @av: arguments.
 *
 * Return: 0 on success, -1 on failure.
 */

int my_unsetenv(char **av)
{
	if (av[1] == NULL)
	{
		perror("unsetenv: Variable not specified");
		return (-1);
	}

	if (unsetenv(av[1]) != 0)
	{
		perror("unsetenv failed");
		return (-1);
	}

	return (0);
}

