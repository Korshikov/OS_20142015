#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "helpers.h"

const unsigned BLOCK_SIZE = 2048;

void print_error() {
    char *msg = strerror(errno);
    write_(STDERR_FILENO, msg, strlen(msg));
    free(msg);
    exit(1);
}

int main() {
    char buffer[BLOCK_SIZE];
    int n;

    while ((n = read_(STDIN_FILENO, buffer, BLOCK_SIZE)) != 0) {
        if (n == -1)
            print_error();

        n = write_(STDOUT_FILENO, buffer, n);
        if (n == -1)
            print_error();
    }

    return 0;
}