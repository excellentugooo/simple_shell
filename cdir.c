#include "main.h"

/**
 * cdir - function changes the working directory
 * @av: arguments.
 *
 * Return: 1 on success, 0 on failure.
 */
int cdir(char **av)
{
	char *dir = av[1];
	char *cwd;

	if (dir == NULL || strcmp(dir, "~") == 0)
		dir = getenv("HOME");

	else if (strcmp(dir, "-") == 0)
	{
		dir = getenv("OLDPWD");
		writes("dir", 1);
	}

	if (chdir(dir) != 0)
	{
		perror("cd failed");
		return (0);
	}
	cwd = getcwd(NULL, 0);
	setenv("PWD", cwd, 1);
	free(cwd);

	return (1);
}

