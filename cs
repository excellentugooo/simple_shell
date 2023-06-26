#include "main.h"

/**
 * cdir - funtion changes the working directory
 * @av: name directory
 *
 * Return: 1 on success, 0 on failure.
 */
int cdir(char **av)
{
	if (av[1] == NULL)
	{
		perror("cdir failed\n");
	}
	else
	{
		if (chdir(av[1]) != 0)
		{
			perror("error\n");
		}
	}
	return (-1);
}
