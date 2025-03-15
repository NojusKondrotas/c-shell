#include <stdio.h>
#include <stdlib.h>

int main(int, char*);

void shell_loop(){
    char *line;
    char **args;
    int status;

    do{
        printf("> ");
        line = shell_read();
        args = shell_line_split(line);
        status = shell_execute(args);

        free(line);
        free(args);
    } while(status);
}

char* shell_read();

char** shell_line_split(char*);

int shell_execute(char**);