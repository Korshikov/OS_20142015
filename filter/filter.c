#include <errno.h>
#include <helpers.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

const size_t BUFFER_SIZE = 4096;


void print_err() {
    char *msg = strerror(errno);
    write_(STDERR_FILENO, msg, strlen(msg));
}



void write_char(char c)
{
    write_(STDOUT_FILENO, &c, 1);
}

void execute(char* file_path, char* const args [], char* str) {
    if (spawn(file_path, args)==0) {
        write_(STDOUT_FILENO, str, strlen(str));
        write_char('\n');
    }
}


int main(int arg_len, char* args[]) {
    char* file_path = args[1];
    char* spawn_args[arg_len];

    char buf[BUFFER_SIZE];

    int i=0;

    for (i = 0; i < arg_len - 1;) {
        spawn_args[i] = args[++i];
    }
    spawn_args[i] = buf;

    int read_cnt;

    while((read_cnt = read_until(STDIN_FILENO, buf, sizeof(buf), '\n'))>0)
    {
        if (read_cnt == -1) {
            print_err();
        }
        if((read_cnt == 1)&&(buf[0]=='\n'))
        {
            continue;
        }
        buf[strlen(buf)-1]=0;
        write_char('d');
        write_(STDOUT_FILENO,buf,strlen(buf));
        write_char('\n');
        execute(file_path, spawn_args, buf);
    }

    return 0;
}