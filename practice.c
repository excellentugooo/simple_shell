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
	char *input = NULL, *inputcpy= NULL;
	int i;
	char *path = NULL;
        ssize_t rvalue = 0;
        size_t n = 0;
	char **enp = env;
        pid_t value;

        put_char('$');
        put_char(' ');
	
        while(1)
        {

        	rvalue = getline(&input, &n, stdin);
                if (rvalue == -1)
                        return(-1);
		inputcpy = strdup(input);
/*		path = find_path(input);*/
		i = 0;
		while (inputcpy[i] != '\0')
		{
			if (inputcpy[i] == '\n')
				inputcpy[i] = '\0';
			i++;
		}
		av = tokenize(inputcpy, " \n");
		path = find_path(input);
		if (path == NULL)
		{
			if (av == NULL || av[0] == NULL)
    			{
        			free(input);
				free(inputcpy);
        			exit(0);
    			}
			if (str_cmp(av[0], "exit") == 0)
			{
                	free(input);
			free(inputcpy);
                	free(av);
                	exit(0);
            		}
			else if (str_cmp(av[0], "env") == 0)
			{
				i = 0;
				while (enp[i] != NULL)
				{
					printf("%s\n", enp[i]);
					i++;
					put_char('$');
                        		put_char(' ');

				}

			}
            		else
			{
			printf("%s: command not found\n", av[0]);
			put_char('$');
        		put_char(' ');
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
                	        put_char('$');
				put_char(' ');
	                }
		}
		free(input);
		free(inputcpy);
        }
        return (0);
}
