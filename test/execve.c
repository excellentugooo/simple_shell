#include "main.h"

/**
 * exec_ve - it creates a new child process and performs the execve
 * @path: pathe the command takes
 * @av: argument vector
 * @env: evironment variable
 */

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
