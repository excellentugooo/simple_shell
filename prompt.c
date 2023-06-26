#include "main.h"

/**
* prompt - prints promt
*/

void prompt(void)
{
	if (isatty(STDIN_FILENO) == 1)
		writes("simpleshell$ ", 1);
}
