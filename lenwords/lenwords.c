#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <helpers.h>

const size_t BUFFER_SIZE = 4096;

void print_err() {
    char *msg = strerror(errno);
    write_(STDERR_FILENO, msg, strlen(msg));
}

void reverse(char *begin, char *end) {
    char temp;
    while(begin<end)
    {
        temp = *end;
        *(end--) = *begin;
        *(begin++) = temp;

    }
    return;
}

int main() {
    char buffer[BUFFER_SIZE];
    int n;

    while ((n = read_until(STDIN_FILENO, buffer, BUFFER_SIZE, ' ')) != 0) {
        if (n == -1) {
            print_err();
        }

        buffer = sprintf("%d ",(buffer + n - 2 + (buffer[n - 1] != ' ')-buffer));
        if (write(STDOUT_FILENO, buffer, n) == -1) {
            print_err();
        }

    }

    return 0;
}