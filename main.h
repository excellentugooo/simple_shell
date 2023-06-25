#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int put_char(char c);
char **tokenize(char *input, char *delim);
void writes(char *s, int stream);
void exec_ve(char *path, char *av[], char *env[]);
int _atoi(char *s);
char *get_env(char *name);
void set_env(char *av[]);
void unset_env(char *av[]);
void cd(char *av[]);
char *str_str(char *haystack, char *needle);
void rmline(char *input);
void envip(char *env[]);
void ex_it(char *av[]);
char *find_path(char *input);
char *str_cpy(char *dest, char *src);
int str_len(char *s);
char *str_cat(char *dest, char *src);
char *str_dup(char *str);
int str_cmp(char *s1, char *s2);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);
int _sch(char *s, char c);
char *str_tok(char *s, char *d);

#endif
