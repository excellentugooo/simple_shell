#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <malloc.h>

/**
 * main - a simple shell
 * @ac: argument count
 * @av: argument vector
 * @env: environment variable
 *
 * Return: 0 on success, -1 on failure
 */

int main(__attribute__((unused)) int ac, char *av[], char *env[])
{
	char *input = NULL;
	char *cmd = NULL;
	ssize_t rvalue = 0;
	size_t n = 0;

	while(1)
	{
		writes("simpleshell$ ", 1);

        	rvalue = getline(&input, &n, stdin);
                if (rvalue == -1)
                        return(-1);
		rmline(input);
		rmspace(input);
		rmit(input);
		cmd = strtok(input, ";");
		while (cmd != NULL)
		{
			rmspace(cmd);
			execute_cmd(av, env, cmd);
			cmd = strtok(NULL, ";");
		}
		free(input);
		free_double_ptr(av);
        }
/*	free_double_ptr(av);*/
        return (0);
}
