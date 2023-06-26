#include "main.h"

void int_shell(void)
{
	char *input = NULL;
	char **av;
	int stat = -1;

	do{
		prompt();
		input = getint();
		av = split_line(input);
		stat = execute_args(av);
		free(input);
		free(av);

		if (stat >= 0)
			exit(stat);
	}while (stat == -1);

}	

void non_intshell(void)
{
        char *input = NULL;
        char **av;
        int stat = -1;

        do{
                input = read_stream();
				av = split_line(input);
                stat = execute_args(av);
                free(input);
                free(av);

                if (stat >= 0)
                        exit(stat);
        }while (stat == -1);
}
