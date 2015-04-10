#include <stdlib.h>
#include <sys/types.h>
#include "bufio.h"
#include "helpers.h"

struct buf_t* buf_new(size_t capacity) {
    char *new_data = malloc(capacity);
    if (!new_data) {
        return NULL;
    }

    struct buf_t *new_buf_t = malloc(sizeof(struct buf_t));
    new_buf_t->size = 0;
    new_buf_t->data = new_data;
    new_buf_t->capacity = capacity;
    new_buf_t->pos=0;
    return new_buf_t;
}

void buf_free(struct buf_t* rhs) {
    free(rhs->data);
    free(rhs);
}

size_t buf_capacity(struct buf_t* rhs) {
    return rhs->capacity;
}

size_t buf_size(struct buf_t* rhs) {
    return rhs->size;
}

ssize_t buf_fill(int fd, struct buf_t *buf, size_t required) {
    int counter = read_(fd, buf->data, required);
    if(counter>=0)
    {
		buf->size = counter;
    }
    else
    {
    	buf->size = 0;
    }
    return counter;
}

ssize_t buf_flush(int fd, struct buf_t *buf, size_t required) {
    return write_(fd, buf->data, required);
}

ssize_t buf_getline(int fd, struct buf_t *buf, char* dest)
{
    int position = 0;
    while(1)
    {
        if(buf->size<=buf->pos)
        {
            int counter = read_(fd, buf->data, buf->capacity);
            buf->pos=0;
            if(counter>0)
            {
                buf->size = counter;
            }   
            else
            {
                buf->size = 0;
                dest[++position] = 0;
                return counter;
            }
            
        }
        while(buf->pos<buf->size)
        {
            if((dest[position++]=buf->data[buf->pos++])=='\n')
            {
                dest[position-1]=0;
                return position;
            }
        }
    }
}