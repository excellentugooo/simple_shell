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

#define TOK_DELIM " \t\r\n\a\""
extern char **environ;


int put_char(char c);
void free_double_ptr(char **ptr);
char **tokenize(char *input, char *delim);
void writes(char *s, int stream);
void prompt();
char *getint(void);
int exec_vp(char *av[]);
char *read_stream(void);
int own_exit(char **args);
int env(char **args);
int cd(char **args);
int assist(char **args);
int execute_args(char **args);
char **split_line(char *line);
void non_intshell(void);
void int_shell(void);

void exec_ve(char *path, char *av[], char *env[]);
int _atoi(char *s);
char *get_env(char *enviv);
void set_env(char *av[]);
void unset_env(char *av[]);
/*void cd(char *av[]);*/
void rmspace(char *input);
void *re_alloc(void *ptr, size_t size);
void rmit(char *input);
void execute_cmd(char *av[], char *env[], char *cmd);
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
int srchdelim(char *s, char c);
char *str_tok(char *s, char *d);
char *mem_cpy(char *dest, char *src, unsigned int n);

#endif
