#include "main.h"

/**
 * main - a simple shell
 * Return: 0 on success
 */

int main(void)
{

	if (isatty(STDIN_FILENO) == 1)
	{
		int_shell();
	}
	else
	{
		non_intshell();
	}
	return (0);
}
