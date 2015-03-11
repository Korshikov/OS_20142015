#ifndef HELPERS_FUNCTIONS
#define HELPERS_FUNCTIONS

#include <sys/types.h>

//from man
ssize_t read_(int fd, void *buf, size_t count);
ssize_t write_(int fd, const void *buf, size_t count);

#endif //HELPERS_FUNCTIONS