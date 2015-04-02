#include <unistd.h>
#include "bufio.h"

const int BUFFER_SIZE = 2048;

int main() {
    struct buf_t* buffer;
    buffer = buf_new(BUFFER_SIZE);

    int n;
    n=0;

    while (n!=-1 && (n = buf_fill(STDIN_FILENO, buffer, BUFFER_SIZE)) > 0) {
        n = buf_flush(STDOUT_FILENO, buffer, n);
    }

    buf_free(buffer);
    return 0;
}
