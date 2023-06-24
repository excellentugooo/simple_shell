#include "main.h"

void envip(char *env[])
{
	char **enp = env;
	int i;

	 i = 0;
	 while (enp[i] != NULL)
	 {
		 writes("env[i]", 1);
		 i++;
	 }
}
