#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "bufio.h"
#include "helpers.h"

const size_t BUFFER_SIZE = 4096;


void print_err() {
    char *msg = strerror(errno);
    write_(STDERR_FILENO, msg, strlen(msg));
}



void println(int fd, const char * str) {
    write_(fd, str, strlen(str));
    char c = '\n';
    write_(fd, &c, 1);
}



int main(int arg_len, char* args[]) {
    char* file_path = args[1];
    char** spawn_args = malloc(sizeof(char*)*(arg_len+1));

    struct buf_t* buffer;
    buffer = buf_new(BUFFER_SIZE);
    char line[BUFFER_SIZE];

    int i=0;
    int pos=0;
    int n;


    for (i = 0; i < arg_len - 1;++i) {
        spawn_args[i] = args[i+1];
    }
    spawn_args[i] = line;
    spawn_args[arg_len] = 0;


   do{
        line[0]=0;
        n = buf_getline(STDIN_FILENO, buffer, line);
        if((!(n&1))&&(n))
        {
            if (spawn(spawn_args[0], spawn_args) == 0) {
                println(STDOUT_FILENO, line);
            }
        }
        
    } while (n >= 0);

    free(spawn_args);

    return 0;
}