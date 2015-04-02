#include <sys/types.h>
#include <unistd.h>
#include "helpers.h"

ssize_t read_(int fd, void *buf, size_t count) {
    ssize_t result_len = 0;
    while (1) {
        ssize_t tmp_len = read(fd, buf + result_len, count - result_len);
        if (tmp_len == -1){
            return -1; //error
        }
        if(tmp_len == 0){
            return result_len; //EOF
        }
        result_len += tmp_len;
        if (result_len == count) {
            return result_len; //complite
        }
    }
}

ssize_t write_(int fd, const void *buf, size_t count) {
    ssize_t result_len = 0;
    while (1) {
        ssize_t tmp_len = write(fd, buf + result_len, count - result_len);
        if (tmp_len == -1){
            return -1; //error
        }
        result_len += tmp_len;
        if (result_len == count) {
            return result_len; //complite
        }
  }

}

ssize_t read_until(int fd, void * buf, size_t count, char delimiter) {
    int current_counter, n;
    for (current_counter = 0; current_counter < count; current_counter++) {
        n = read(fd, buf + current_counter, 1);
        if (n == -1){
            return -1;
        }
        if (n == 0){
            return current_counter;
        }
        if ((((char*)buf)[current_counter]) == delimiter)
        {
            return ++current_counter;
        }
    }
    return current_counter; 
}

int spawn(const char * file, char * const argv [])
{
    pid_t pid = fork();
    if (!pid) {
        execvp(file, argv);
    }
    
    int ret_code;
    wait(&ret_code);

    return ret_code;
}