#include "main.h"

/**
 * excute_built -  execute command
 * @av: command
 *
 * Return: 1 on sucess, 0 on failure
 */
int excute_built(char **av)
{
	char *built_list[] = {
		"cd",
		"env",
		"help",
		"exit"
	};
	int (*built_function[])(char **) = {
		&cdir,
		&set_env,
		&he_lp,
		&my_exit
	};
	unsigned long int j;

	if (av[0] == NULL)
		return (-1);

	j = 0;
	while (j < sizeof(built_list) / sizeof(char *))
	{
		if (strcmp(av[0], built_list[j]) == 0)
		{
			return ((*built_function[j])(av));
		}
		j++;
	}
	return (exec_vp(av));
}
