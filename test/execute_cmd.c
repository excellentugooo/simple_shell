#include "main.h"

/**
 * execute_cmd - it executes the commands received
 * @av: argument vector
 * @env: enviroment variable
 * @cmd: command
 */

void execute_cmd(char *av[], char *env[], char *cmd)
{
	char *path = NULL;

	av = tokenize(cmd, " \n");
	path = find_path(cmd);
	if (path == NULL)
	{
		if (av == NULL || av[0] == NULL)
		{
			free(cmd);
			exit(0);
		}
		else if (str_cmp(av[0], "exit") == 0)
			ex_it(av);
		else if (str_cmp(av[0], "env") == 0)
			envip(env);
		else if (str_cmp(av[0], "setenv") == 0)
			set_env(av);
		else if (strcmp(av[0], "unsetenv") == 0)
			unset_env(av);
		else if (strcmp(av[0], "cd") == 0)
			cd(av);
		else
			writes(":command not found\n", 1);
	}
	else
	{
		exec_ve(path, av, env);
	}
}
