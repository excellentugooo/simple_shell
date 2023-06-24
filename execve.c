#include "main.h"

void exec_ve(char *path, char *av[], char *env[])
{
	pid_t value;
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
