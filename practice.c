include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int ac, char *av[])
{
        char *input = NULL, *inputcopy = NULL;
        int i;
        ssize_t rvalue = 0;
        size_t n;
        const char *delim = " \n";
        char *token = NULL;
        pid_t value;

        putchar('$');
        putchar(' ');

        while(1)
        {
                rvalue = getline(&input, &n, stdin);
                if (rvalue == -1)
                        return (-1);
                inputcopy = strdup(input);

                token = strtok(input, delim);
                ac = 0;
                while (token != NULL)
		                {
                        ac++;
                        token = strtok(NULL, delim);
                }
                ac++;
                av = malloc(sizeof(char *) * ac);
                token = strtok(inputcopy, delim);
                for (i = 0; i < ac; i++)
                {
                        av[i] = token;
                        token = strtok(NULL, delim);
                }
                av[i] = NULL;

                value = fork();
                if (value == -1)
                        exit(EXIT_FAILURE);
                else if (value == 0)
                {
                        execve(av[0], av, NULL);

                        perror("Error");
                        exit(EXIT_FAILURE);
                }
                else
                {
                        wait(NULL);
                        putchar('$');
			putchar(' ');
                }
        }
        free(input);
	free (inputcopy);
	free (av);
        return (0);
}
