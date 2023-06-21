#include "main.h"

/**
* find_path - gets to path to an argument.
* return: path.
*/

char *find_path(char *input)
{
	char *path, *pathcopy;
	char *token, *filepath;
	int inlen, toklen;
	struct stat buff;
	char *delim = ":";

	path = getenv("PATH");

	if (path)
	{
		pathcopy = strdup(path);
		inlen = strlen(input);

		token = strtok(pathcopy, delim);
		while (token != NULL)
		{
			toklen = strlen(token);
			filepath = malloc(inlen + toklen + 2);
			strcpy(filepath, token);
			strcat(filepath, "/");
			strcat(filepath, input);
	/*		strcat(filepath, "\0");*/

			if (stat(filepath, &buff) == 0)
			{
				free(pathcopy);
				return (filepath);
			}
			else
			{
				free(filepath);
				token = strtok(NULL, delim);
			}
		}
		free(pathcopy);
		if (stat(input, &buff) == 0)
			return (input);
		return(NULL);
	}
	return (NULL);
}

