#include <stdbool.h>
#include <stdint.h>
#include <string.h>

struct mem_block {
    size_t size;
    bool is_free;
};

void *init_mem();
void *my_malloc(size_t size); // Allocate a block of memory
void my_free(void *ptr); // Free a block of memory