#include "main.h"

/**
 * parse - tokenizes
 * @input: string
 *
 * Return: pointer to array
 */
char **parse(char *input)
{
	int buf = 64, i = 0;
	char **ptrtokens = malloc(buf * sizeof(char *));
	char *strtoken;
	char *delim = " \n";

	if (!ptrtokens)
		exit(EXIT_FAILURE);
	strtoken = strtok(input, delim);
	while (strtoken != NULL)
	{
		if (strtoken[0] == '#')
		{
			break;
		}
		ptrtokens[i] = strtoken;
		i++;
		if (i >= buf)
		{
			buf += buf;
			ptrtokens = realloc(ptrtokens, buf * sizeof(char *));
			if (!ptrtokens)
			{
				exit(EXIT_FAILURE);
			}
		}
		strtoken = strtok(NULL, delim);
	}
	ptrtokens[i] = NULL;
	return (ptrtokens);
}
