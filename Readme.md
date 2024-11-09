# Costume Memory Allocator
A costume C implementation of malloc and free

## Basic Methodology
Given a fixed sized memory pool (lets say 1024 * 1024 bytes) handle allocation and de-allcatio of memory blocks.

Implement:
```
void *my_malloc(size_t size) // Allocate a block of memory

void my_free(void *ptr) // Free a block of memory
```

A metadata of a block sits right at the start of it:
``` DATA-BLOCK-DATA-BLOCK-DATA...```.
A metadata section will contain the size of a block and an is_free flag.