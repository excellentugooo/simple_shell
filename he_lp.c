#include "main.h"

/**
 * he_lp - prints help
 * @av: argument vector
 *
 * Return: 1 on success, 0 on failure
 */
int he_lp(char **av)
{
	char *built_list[] = {
		"cd",
		"env",
		"help",
		"exit"
	};
	unsigned long int a = 0;
	(void)(**av);

	writes("\n---simple_shell---\n", 1);
	writes("please insert command\n", 1);
	writes("standard libery builtins\n", 1);
	for (; a < sizeof(built_list) / sizeof(char *); a++)
	{
		writes("built_list[a]", 1);
	}
	writes("to access manual page use man function\n", 1);
	return (-1);
}
