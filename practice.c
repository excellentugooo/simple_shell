#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>


int main(__attribute__((unused)) int ac, char *av[], char *env[])
{
	char *input = NULL;
	char *path = NULL;
        ssize_t rvalue = 0;
        size_t n = 0;

        while(1)
        {
		writes("simpleshell$ ", 1);

        	rvalue = get_line(&input, &n, stdin);
                if (rvalue == -1)
                        return(-1);
		rmline(input);
		av = tokenize(input, " \n");
		path = find_path(input);
		if (path == NULL)
		{
			if (av == NULL || av[0] == NULL)
    			{
        			free(input);
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
	free(input);
        return (0);
}
