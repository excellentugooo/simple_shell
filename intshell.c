#include "main.h"

int main(__attribute__((unused)) int ac, char **av)
{
	char *input = NULL;
	/*char **av;*/
	int stat = -1;

	do{
		prompt();
		input = getint();
		stat = exec_vp(av);
		free(input);
		free(av);

		if (stat >= 0)
			exit(stat);
	}while (stat == -1);
	return (0);

}	

/*void non_intshell(void)
{
        char *input = NULL;
        char *av[] = NULL;
        int stat = -1;

        do{
                input = getint();
                stat = execvp(av);
                free(input);
                free(av);

                if (stat >= 0)
                        exit(stat);
        }while (stat == -1);
}*/
