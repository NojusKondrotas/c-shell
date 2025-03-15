#include <stdio.h>
#include <stdlib.h>

char* shell_read();

char** shell_line_split(char*);

int shell_execute(char**);

int main(int argc, char* argv){
    shell_loop();

    return EXIT_SUCCESS;
}

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