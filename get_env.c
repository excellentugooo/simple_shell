#include "main.h"

extern char **environ;
char *get_env(char *name)
{
        int i = 0;
        int lenght = str_len(name);
	char *check;

        while(environ[i] != NULL)
        {
                check = strstr(environ[i], name);
                if (check != NULL)
                {
                	return (check + lenght + 1);
                }
                i++;
        }
        return NULL;

}
