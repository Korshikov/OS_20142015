#ifndef HELPERS_FUNCTIONS
#define HELPERS_FUNCTIONS

#include <sys/types.h>

//from man
ssize_t read_(int fd, void *buf, size_t count);
ssize_t write_(int fd, const void *buf, size_t count);
<<<<<<< HEAD
ssize_t read_until(int fd, void * buf, size_t count, char delimiter);
=======
>>>>>>> caf9b91... first task result commit

#endif //HELPERS_FUNCTIONS