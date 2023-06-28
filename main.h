#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

extern char **environ;


int put_char(char c);
void writes(char *s, int stream);
void prompt(void);
char *getint(void);
int exec_vp(char *av[]);
char *get_strem(FILE *file);
int my_exit(char **av);
int set_env(char **av);
int cdir(char **av);
int he_lp(char **av);
int excute_built(char **av);
char **parse(char *input);
void non_intshell(char *filename);
void int_shell(void);
int my_setenv(char **av);
int my_unsetenv(char **av);

#endif
