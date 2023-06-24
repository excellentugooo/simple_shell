#include "main.h"

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
