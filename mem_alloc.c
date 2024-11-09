#include "mem_alloc.h"

#define MEMORY_SIZE 1024

char mem_pool[MEMORY_SIZE];

void *init_mem() {
    struct mem_block head = {MEMORY_SIZE - sizeof(struct mem_block), true};

    memcpy(mem_pool, &head, sizeof(struct mem_block)); // copy the block into the memory pool

    return mem_pool; // return for debugging
}

void *my_malloc(size_t size) {
    struct mem_block *block = mem_pool;
    struct mem_block new_block;

    // Search for the first free block with enough size
    while ((char*) block < mem_pool + MEMORY_SIZE) {
        if (block->is_free && block->size >= size) {
            break; // found a suitable block
        }
        block = ( struct mem_block *)((char *)block + block->size + sizeof(struct mem_block));
    }

    if ((char*)block >= mem_pool + MEMORY_SIZE)
        return NULL;

    block->is_free = false;

     // Check if there is enough space to split the block
    if (block->size >= size + sizeof(struct mem_block) + 1) {
        // Create a new block for the remaining free space
        struct mem_block *new_block = (struct mem_block *)((char *)block + sizeof(struct mem_block) + size);
        new_block->is_free = true;
        new_block->size = block->size - size - sizeof(struct mem_block);
        
        // Update the size of the allocated block
        block->size = size;
    }

    return (char *)block + sizeof(struct mem_block);
}

void my_free(void *ptr) {
    struct mem_block *block = mem_pool;

    if ((char*)block >= mem_pool + MEMORY_SIZE)
        return;

    // Search for the correct block
    while ((char*)block < (char*)ptr) {
        // Check if the current block is the desired free destination
        if ((char *)block  == (char *)ptr - sizeof(struct mem_block)) {
            block->is_free = true;
            return;
        }
        block = (struct mem_block *)((char *)block + block->size + sizeof(struct mem_block));
    }
}

void print_memory() {
    for(int i=0; i<MEMORY_SIZE; i++) {
        if((mem_pool[i] == 0))
            putc('-', stdout);
        else
            putc(mem_pool[i], stdout);
    }
}