#include "main.h"

/**
 * main - a simple shell
 * @arc: argument count
 * @arv: argument vector
 * Return: 0 on success
 */

int main(int arc, char *arv[])
{
	char *filename = arv[1];
	(void) arc;

	if (isatty(STDIN_FILENO) == 1)
	{
		int_shell();
	}
	else
	{
		non_intshell(filename);
	}
	return (0);
}
