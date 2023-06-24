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
	int i;
	char *path = NULL;
        ssize_t rvalue = 0;
        size_t n = 0;
	char **enp = env;
        pid_t value;

        while(1)
        {
		writes("simpleshell$ ", 1);

        	rvalue = getline(&input, &n, stdin);
                if (rvalue == -1)
                        return(-1);
		i = 0;
		while (input[i] != '\0')
		{
			if (input[i] == '\n')
				input[i] = '\0';
			i++;
		}
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
			{
                		exit(0);
            		}
			else if (str_cmp(av[0], "env") == 0)
			{
				i = 0;
				while (enp[i] != NULL)
				{
					writes("env[i]", 1);
					i++;
				}

			}
            		else
			{
				writes(":command not found\n", 1);
			}
		}
		else
		{
			value = fork();

	                if (value == -1)
                        	exit(EXIT_FAILURE);
                	else if (value == 0)
        	        {
	                        execve(path, av, env);

                         	perror("Error");
			 	free(av);
                        	exit(EXIT_FAILURE);
                	}
        	        else
	                {
                        	wait(NULL);
	                }
		}
        }
	free(input);
        return (0);
}
