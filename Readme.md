# Custom Memory Allocator
A custom C implementation of malloc and free

# Basic Methodology
Given a fixed sized memory pool handle allocation and de-allcatio of memory blocks.

Implement:
```
void *my_malloc(size_t size) // Allocate a block of memory

void my_free(void *ptr) // Free a block of memory
```

A metadata of a block sits right at the start of it:
``` DATA-BLOCK-DATA-BLOCK-DATA...```.

A metadata section will contain the size of a block and an is_free flag:

```
struct mem_block {
    size_t size;
    bool is_free;
};
```

# Implementation
## Memory initialization
Before we start allocation memory we need to initialize the memory space. The initialization is easy, just set the first metadata block.

## Malloc Implementation
The way to implement a malloc is very straight forward:

1. Search for a block that is free AND is greater or equal in size to the desired memory
2. Mark the block occupied and change its size to the desired size(round up to a multiple of 16)
3. Create a new metadata block after the allocated memory
4. Set the new block size to: Previous_Block_Size - alloc_size - sizeof(mem_block)

In case the memory is full, return a null pointer.

## Free Implementation 
### The easy way
The easiest way to free a memory block is simple, search for the given pointer in memory and mark it free.