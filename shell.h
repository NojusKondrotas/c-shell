#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char *strtok_r(char *, const char *, char **);

#define SHELL_RL_BUFSIZE 1024

#define SHELL_TOK_BUFSIZE 64
#define SHELL_TOK_DELIM " \t\r\n\a"

void zero(char *str, int size){
    char *p;
    int n;

    for(n=0, p=str; n < size; p++, n++)
        *p = 0;

    return;
}