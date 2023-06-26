#include "main.h"

void unset_env(char *av[])
{
	if (av[1] == NULL)
	{
		writes("unsetenv: Invalid argument\n", 1);
	}
	else
	{
		if (unsetenv(av[1]) != 0)
		{
			writes("unsetenv: Failed to unset environment variable\n", 1);
		}
	}
}
