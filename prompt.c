#include "main.h"

void prompt()
{
	if (isatty(STDIN_FILENO) == 1)
		writes("simpleshell$ ", 1);
}
