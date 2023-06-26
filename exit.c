#include "main.h"

/**
 * ex_it - it performs exit built in function with status
 * @av: argument to exit
 */

void ex_it(char *av[])
{
	int status;

	if (av[1] != NULL)
	{
		status = _atoi(av[1]);
		exit(status);
	}
	else
	{
		exit(0);
	}
}
