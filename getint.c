#include "main.h"

char *getint(void)
{
	char *input = NULL;
	size_t num = 0;

	if (getline(&input, &num, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(input);
			perror("getline failed");
			exit(EXIT_FAILURE);
		}
	}
	return (input);
}
