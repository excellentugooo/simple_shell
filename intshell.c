#include "main.h"

/**
* int_shell - shell for interctive mode.
*/

void int_shell(void)
{
	char *input = NULL;
	char **av;
	int stat = -1;

	do {
		prompt();
		input = getint();
		av = parse(input);
		stat = excute_built(av);
		free(input);
		free(av);

		if (stat >= 0)
			exit(stat);
	} while (stat == -1);

}

/**
* non_intshell - shell for non interactive mode.
*/
void non_intshell(void)
{
	char *input = NULL;
	char **av;
	int stat = -1;

	do {
		input = get_strem();
		av = parse(input);
		stat = excute_built(av);
		free(input);
		free(av);

		if (stat >= 0)
			exit(stat);
	} while (stat == -1);
}
