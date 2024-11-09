#include "mem_alloc.h"

#define MEMORY_SIZE 1024

char mem_pool[MEMORY_SIZE];

void* init_mem() {
    struct mem_block head = {MEMORY_SIZE - sizeof(struct mem_block), true};

    memcpy(mem_pool, &head, sizeof(struct mem_block));  

    return mem_pool;  
}