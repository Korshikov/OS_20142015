#ifndef HELPERS_FUNCTIONS
#define HELPERS_FUNCTIONS

#include <sys/types.h>

//from man
ssize_t read_(int fd, void *buf, size_t count);
ssize_t write_(int fd, const void *buf, size_t count);
ssize_t read_until(int fd, void * buf, size_t count, char delimiter);

int spawn(const char * file, char * const argv []);

#endif //HELPERS_FUNCTIONS