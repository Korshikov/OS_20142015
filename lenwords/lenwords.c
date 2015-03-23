#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <helpers.h>

const size_t BUFFER_SIZE = 4097;

void print_err() {
    char *msg = strerror(errno);
    write_(STDERR_FILENO, msg, strlen(msg));
}

int main() {
    char buffer[BUFFER_SIZE];
    int n;

    while ((n = read_until(STDIN_FILENO, buffer, BUFFER_SIZE, ' ')) != 0) {
        if (n == -1) {
            print_err();
        }

        n = sprintf(buffer,"%d ",(n - (buffer[n - 1] == ' ')));
        if (write(STDOUT_FILENO, buffer, n) == -1) {
            print_err();
        }

    }

    return 0;
}