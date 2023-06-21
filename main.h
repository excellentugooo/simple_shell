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
char *find_path(char *input);
char *str_cpy(char *dest, char *src);
int str_len(char *s);
char *str_cat(char *dest, char *src);
char *str_dup(char *str);
int str_cmp(char *s1, char *s2);

#endif
