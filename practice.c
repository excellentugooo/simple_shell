#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>


int main(__attribute__((unused)) int ac, char *av[], char *env[])
{
	char *input = NULL;
	char *cmd = NULL;
        ssize_t rvalue = 0;
        size_t n = 0;

        while(1)
        {
		writes("simpleshell$ ", 1);

        	rvalue = get_line(&input, &n, stdin);
                if (rvalue == -1)
                        return(-1);
		rmline(input);
		rmspace(input);
		rmit(input);
		cmd = strtok(input, ";");
		while (cmd != NULL)
		{
			rmspace(cmd);
			execute_cmd(av, env, cmd);
			cmd = strtok(NULL, ";");
		}
        }
	free(input);
        return (0);
}
