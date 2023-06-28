#include "main.h"

/**
* int_shell - shell for interctive mode.
*/

void int_shell(void)
{
	char *input = NULL;
	char **av;
	int stat = -1;
	char *cmd = NULL;

	do {
		prompt();
		input = getint();
		cmd = strtok(input, ";");
		while (cmd != NULL)
		{
			av = parse(cmd);
			stat = excute_built(av);
			cmd = strtok(NULL, ";");
		}
		free(input);
		free(av);

		if (stat >= 0)
			exit(stat);
	} while (stat == -1);

}

/**
* non_intshell - shell for non interactive mode.
*
*/
void non_intshell(void)
{
	char *input = NULL;
	char **av;
	int stat = -1;
	char *cmd = NULL;



	do {
		input = get_strem();
		cmd = strtok(input, ";");
		while (cmd != NULL)
		{
			av = parse(cmd);
			stat = excute_built(av);
			cmd = strtok(NULL, ";");
		}
		free(input);
		free(av);

		if (stat >= 0)
			exit(stat);
	} while (stat == -1);
}
