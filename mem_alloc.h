struct mem_block {
    size_t size;
    bool is_free;
};

void *my_malloc(size_t size); // Allocate a block of memory

void my_free(void *ptr); // Free a block of memory