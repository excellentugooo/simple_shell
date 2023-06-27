#include "main.h"

/**
* exec_vp - executes and creates new child process.
* @av: takes command
* Return: -1
*/

int exec_vp(char *av[])
{
	pid_t value;
	int stat;

	value = fork();
	if (value ==  0)
	{
		if (execvp(av[0], av) == -1)

		perror("Error");
		free(av);
		exit(EXIT_FAILURE);
	}
	else if (value < 0)
	{
		perror("process failed");
	}
	else
	{
		do {
			waitpid(value, &stat, WUNTRACED);
		} while (!WIFEXITED(stat) && !WIFSIGNALED(stat));
	}
	return (-1);
}
