#include <stdio.h>
#include <stdlib.h>

#define SHELL_RL_BUFFERSIZE 1024

void zero(char *str, int size){
    char *p;
    int n;

    for(n=0, p=str; n < size; p++, n++)
        *p = 0;

    return;
}