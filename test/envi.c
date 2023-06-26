#include "main.h"

/**
 * envip - prints out the enviroment variable
 * @env: environment variable
 */

void envip(char *env[])
{
	char **enp = env;
	int i;

	i = 0;
	while (enp[i] != NULL)
	{
		writes("env[i]", 1);
		i++;
	}
}
