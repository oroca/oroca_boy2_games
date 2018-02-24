/*
 * mem.c
 *
 *  Created on: Feb 08, 2018
 *      Author: mem
 */



#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>

#include "hw.h"
#include "mem.h"





//-- Internal Variables
//
static uint32_t __heap_start = 0xC0800000;
static uint32_t __heap_limit = 0xC1000000;


//-- External Variables
//


//-- Internal Functions
//
static void *malloc_(size_t size);
static void free_(void *ptr);


//-- External Functions
//



void memInit(uint32_t addr, uint32_t length)
{
  __heap_start = addr;
  __heap_limit = addr + length;
}

void *memMalloc(uint32_t size)
{
  return malloc_(size);
}

void memFree(void *ptr)
{
  free_(ptr);
}



#include <unistd.h>
#include <errno.h>

static inline size_t word_align(size_t size) {
    return size + (sizeof(size_t) - 1) & ~(sizeof(size_t) - 1);
}

struct chunk {
    struct chunk *next, *prev;
    size_t        size;
    int           free;
    void         *data;
};

typedef struct chunk *Chunk;



static caddr_t sbrk_(int incr)
{

  static char *heap_end = (char *)0;
  static char *heap_limit = (char *)0;

  char *prev_heap_end;

  heap_limit = (char *)__heap_limit;

  if (heap_end == 0)
    heap_end = (char *)__heap_start;

  prev_heap_end = heap_end;
  if (heap_end + incr > heap_limit)
  {
    errno = ENOMEM; // not enough memory
    return (caddr_t) -1;
  }

  heap_end += incr;

  return (caddr_t) prev_heap_end;
}

static void *malloc_base() {
    static Chunk b = NULL;
    if (!b) {
        b = (Chunk)sbrk_(word_align(sizeof(struct chunk)));
        if (b == (void*) -1) {
            //_exit(127);
          while(1);
        }
        b->next = NULL;
        b->prev = NULL;
        b->size = 0;
        b->free = 0;
        b->data = NULL;
    }
    return b;
}

static Chunk malloc_chunk_find(size_t s, Chunk *heap) {
    Chunk c = (Chunk)malloc_base();
    for (; c && (!c->free || c->size < s); *heap = c, c = c->next);
    return c;
}

static void malloc_merge_next(Chunk c) {
    c->size = c->size + c->next->size + sizeof(struct chunk);
    c->next = c->next->next;
    if (c->next) {
        c->next->prev = c;
    }
}

static void malloc_split_next(Chunk c, size_t size) {
    Chunk newc = (Chunk)((char*) c + size);
    newc->prev = c;
    newc->next = c->next;
    newc->size = c->size - size;
    newc->free = 1;
    newc->data = newc + 1;
    if (c->next) {
        c->next->prev = newc;
    }
    c->next = newc;
    c->size = size - sizeof(struct chunk);
}

static void *malloc_(size_t size) {
    if (!size) return NULL;
    size_t length = word_align(size + sizeof(struct chunk));
    Chunk prev = NULL;
    Chunk c = malloc_chunk_find(size, &prev);
    if (!c) {
        Chunk newc = (Chunk)sbrk_(length);
        if (newc == (void*) -1) {
            return NULL;
        }
        newc->next = NULL;
        newc->prev = prev;
        newc->size = length - sizeof(struct chunk);
        newc->data = newc + 1;
        prev->next = newc;
        c = newc;
    } else if (length + sizeof(size_t) < c->size) {
        malloc_split_next(c, length);
    }
    c->free = 0;
    return c->data;
}

static void free_(void *ptr) {
    if (!ptr || ptr < malloc_base() || (caddr_t)ptr > sbrk_(0)) return;
    Chunk c = (Chunk) ptr - 1;
    if (c->data != ptr) return;
    c->free = 1;

    if (c->next && c->next->free) {
        malloc_merge_next(c);
    }
    if (c->prev->free) {
        malloc_merge_next(c = c->prev);
    }
    if (!c->next) {
        c->prev->next = NULL;
        sbrk_(- c->size - sizeof(struct chunk));
    }
}

