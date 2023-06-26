#include "main.h"

/**
* my_exit - terminates a process
 * @av: argument.
 *
 * Return: 0 on success
 */
int my_exit(char **av)
{
	if (av[1])
		return (atoi(av[1]));
	else
		return (0);
}
