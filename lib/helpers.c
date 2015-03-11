#include <sys/types.h>
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