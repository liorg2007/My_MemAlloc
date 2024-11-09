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

## Implementation

Of course before we start allocation memory we need to initialize the memory space. The initialization is easy, just initialzie the first metadata block.

## Malloc Implementation
The way to implement a malloc is very straight forward:

1. Search for a block that is free AND is greater or equal in size to the desired memory
2. Mark the block occupied and change its size to the desired size(round up to a multiple of 16)
3. Create a new metadata block after the allocated memory
4. Set the new block size to: Previous_Block_Size - alloc_size - sizeof(mem_block)

In case the memory is full, return a null pointer.