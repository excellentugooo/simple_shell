#include "main.h"

void rmline(char *input)
{
	int i;
	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '\n')
			break;
		i++;
	}
	input[i] = '\0';
}

void rmit(char *input)
{
	int i = 0;

	if (input[i] == '#')
	{
		input[i] = '\0';
	}
/*	while (input[i] != '\0')
	{
		if (input[i] == '#' && input[i - 1] == ' ')
		{
			break;
		}
		i++;
	}
	input[i] = '\0';*/
}

void rmspace(char *input)
{
	int i = 0, j;
	int lenght = str_len(input);

        while (input[i] == ' ')
        {
		i++;
        }
	for (j = 0; j < (lenght - i); j++)
	{
		input[j] = input[i + j];
	}
	input[j] = '\0';
}

