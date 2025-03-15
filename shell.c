#include "shell.h"

void shell_loop();

char *shell_read();

char **shell_line_split(char*);

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

    return;
}

char *shell_read(){
    int buffer_size = SHELL_RL_BUFFERSIZE;
    int position = 0;
    char *buffer = malloc(sizeof(char) * buffer_size);
    //zero(buffer, buffer_size);
    int c;

    if(!buffer){
        fprintf(stderr, "shell: allocation error\n");
        exit(EXIT_FAILURE);
    }

    while(1){
        c = getchar();

        if(c == EOF || c == '\n'){
            buffer[position] = '\0';
            return buffer;
        }
        else{
            buffer[position] = c;
        }
        position++;

        if(position >= buffer_size){
            buffer_size += SHELL_RL_BUFFERSIZE;
            buffer = realloc(buffer, buffer_size);
            if(!buffer){
                fprintf(stderr, "shell: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

char **shell_line_split(char* line){
    return 0;
}

int shell_execute(char** args){
    return 1;
}