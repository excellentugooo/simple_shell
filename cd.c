#include "main.h"

void cd(char *av[])
{
	char *directory = av[1];
	char c_dir[1024];

	if (directory == NULL || str_cmp(directory, "~") == 0)
	{
		directory = get_env("HOME");
	}
	else if (str_cmp(directory, "-") == 0)
	{
		directory = get_env("OLDPWD");
	}
	if (getcwd(c_dir, sizeof(c_dir)) == NULL)
        {
		writes("cd: Failed to get current directory\n", 2);
	}
	else
	{
		if (chdir(directory) != 0)
		{
			writes("cd: no such directory\n", 2);
		}
		else
		{
			setenv("OLDPWD", c_dir, 1);
			setenv("PWD", getcwd(NULL, 0), 1);
		}
	}
}
