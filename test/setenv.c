#include "main.h"

void set_env(char *av[])
{	
	if (av[1] == NULL || av[2] == NULL)
	{
		writes("setenv: Invalid arguments\n", 1);
	}
	else
	{
		if (setenv(av[1], av[2], 1) != 0)
		{
			writes("setenv: Failed to set environment variable\n", 2);
		}
	}
}
