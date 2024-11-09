#include "mem_alloc.h"
#include <stdio.h>

int main() {
    char* mem_pool = (char*)init_mem();
    
    struct mem_block *head = (struct mem_block*)mem_pool;

    char* ptr1 = (char*)my_malloc(sizeof(char) * 16);
    char* ptr2 = (char*)my_malloc(sizeof(char) * 16);
    char* ptr3 = (char*)my_malloc(sizeof(char) * 16);

    fgets(ptr1, 15, stdin);
    fgets(ptr2, 15, stdin);
    fgets(ptr3, 15, stdin);

    print_memory();
    /*
    Memory layout is:
    ptr1-ptr2-ptr3
    */

    my_free(ptr2);
    /*
    Memory layout is:
    ptr1-(free)-ptr3
    */

    char* ptr4 = my_malloc(sizeof(char) * 16);
    memset(ptr4, 0, 16);
    fgets(ptr4, 15, stdin);

    print_memory();
    /*
    Memory layout is:
    ptr1-ptr4-ptr3
    */

    return 0;
}