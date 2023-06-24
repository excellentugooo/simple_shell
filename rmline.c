#include "main.h"

void rmline(char *input)
{
	int i;
	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '\n')
			input[i] = '\0';
		i++;
	}
}
