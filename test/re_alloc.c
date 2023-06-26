#include "main.h"
#include <malloc.h>

/**void* my_callocz4(size_t num, size_t size) {
    size_t total_size = num * size;
    void* ptr = malloc(total_size);

    if (ptr == NULL)
	{
        exit(EXIT_FAILURE);
    }
	memset(ptr, 0, total_size);
    return(ptr);
}*/



void *re_alloc(void *ptr, size_t size) 
{
	void* new_ptr = malloc(size);

    if (size == 0) 
	{
        free(ptr);
        return NULL;
    }

    if (new_ptr == NULL)
	{
		exit(EXIT_FAILURE);
    }

    if (ptr != NULL) {
        size_t old_size = malloc_usable_size(ptr);
        size_t copy_size = old_size < size ? old_size : size;
        mem_cpy(new_ptr, ptr, copy_size);
        free(ptr);
    }

    return new_ptr;
}
