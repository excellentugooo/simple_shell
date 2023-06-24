#include "main.h"

/**
* find_path - gets to path to an argument.
* return: path.
*/

char *find_path(char *input)
{
	char *path = NULL, *pathcopy = NULL;
	char *token = NULL, *filepath = NULL;
	int inlen, toklen;
	struct stat buff;
	char *delim = ":";

	path = get_env("PATH");

	if (path)
	{
		pathcopy = str_dup(path);
		inlen = str_len(input);
		token = strtok(pathcopy, delim);
		while (token != NULL)
		{
			toklen = str_len(token);
			filepath = malloc(inlen + toklen + 2 + 1);
			if (filepath == NULL)
			{
				free(pathcopy);
				return(NULL);
			}
			str_cpy(filepath, token);
			str_cat(filepath, "/");
			str_cat(filepath, input);
			filepath[inlen + toklen + 2] = '\0';

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
	}
	return (NULL);
}
