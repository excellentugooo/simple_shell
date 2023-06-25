#include "main.h"

char **tokenize(char *input, char *delim)
{
	char *inputcopy = NULL;
        int i, numtok;
        char *token = NULL;
	char **buff = NULL;

	inputcopy = str_dup(input);
	if (inputcopy == NULL)
		return (NULL);
        token = str_tok(input, delim);
        numtok = 0;
        while (token != NULL)
        {
        	numtok++;
                token = str_tok(NULL, delim);
        }

        buff = malloc(sizeof(char *) * (numtok + 1));
        if (buff == NULL)
	{
		free(inputcopy);
        	return(NULL);
	}

        token = NULL;
        token = str_tok(inputcopy, delim);
        for (i = 0; i < numtok; i++)
        {
		buff[i] = str_dup(token);
                token = str_tok(NULL, delim);
        }
	buff[i] = NULL;

	free(inputcopy);
	return (buff);
}
