#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>


int main(int ac, char *av[], char *env[])
{
        char *input = NULL, *inputcopy = NULL;
        int i;
	char *path = NULL;
        ssize_t rvalue = 0;
        size_t n;
	char **enp = env;
        const char *delim = " \n";
        char *token = NULL;
        pid_t value;

        putchar('$');
        putchar(' ');

        while(1)
        {
                rvalue = getline(&input, &n, stdin);
                if (rvalue == -1)
                        return (-1);
                inputcopy = strdup(input);

                token = strtok(input, delim);
                ac = 0;
                while (token != NULL)
		                {
                        ac++;
                        token = strtok(NULL, delim);
                }
                ac++;
                av = malloc(sizeof(char *) * ac);
                token = strtok(inputcopy, delim);
                for (i = 0; i < ac; i++)
                {
                        av[i] = token;
                        token = strtok(NULL, delim);
                }
                av[i] = NULL;

		path = find_path(input);
		if (path == NULL)
		{
			if (strcmp(av[0], "exit") == 0)
			{
                	free(input);
                	free(inputcopy);
                	free(av);
                	exit(0);
            		}
			else if (strcmp(av[0], "env") == 0)
			{
				i = 0;
				while (enp[i] != NULL)
				{
					printf("%s\n", enp[i]);
					i++;
					putchar('$');
                        		putchar(' ');

				}

			}
            		else
			{
			printf("%s: command not found\n", av[0]);
			putchar('$');
        		putchar(' ');
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
                        	exit(EXIT_FAILURE);
                	}
        	        else
	                {
                        	wait(NULL);
                	        putchar('$');
				putchar(' ');
	                }
		}
        }
        free(input);
	free (inputcopy);
	free (av);
        return (0);
}
