#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
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

    char buf[BUFFER_SIZE];
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
        n = read_until(STDIN_FILENO, buf, sizeof(buf), '\n');
        for (i = 0; i < n; i++) {
            if (buf[i] == '\n') {
                if (pos != 0) {
                    line[pos] = 0;
                    if (spawn(spawn_args[0], spawn_args) == 0) {
                        println(STDOUT_FILENO, line);
                    }
                }
                pos = 0;
            } else {
                line[pos++] = buf[i];
            }
        }
    } while (n > 0);

    free(spawn_args);

    return 0;
}