#include "main.h"

int exec_vp(char *av[])
{
	pid_t value;
	int stat;

	value = fork();
	if (value ==  0)
	{
		if (execvp(av[0], av) == -1)

		perror("no child process");
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
