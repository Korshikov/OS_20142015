#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <helpers.h>

<<<<<<< HEAD
const size_t BUFFER_SIZE = 4097;
=======
const size_t BUFFER_SIZE = 4096;
>>>>>>> c6440ed... lenwords

void print_err() {
    char *msg = strerror(errno);
    write_(STDERR_FILENO, msg, strlen(msg));
}

<<<<<<< HEAD
=======
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

>>>>>>> c6440ed... lenwords
int main() {
    char buffer[BUFFER_SIZE];
    int n;

    while ((n = read_until(STDIN_FILENO, buffer, BUFFER_SIZE, ' ')) != 0) {
        if (n == -1) {
            print_err();
        }

<<<<<<< HEAD
        n = sprintf(buffer,"%d ",(n - (buffer[n - 1] == ' ')));
=======
        buffer = sprintf("%d ",(buffer + n - 2 + (buffer[n - 1] != ' ')-buffer));
>>>>>>> c6440ed... lenwords
        if (write(STDOUT_FILENO, buffer, n) == -1) {
            print_err();
        }

    }

    return 0;
}