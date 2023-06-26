#include "main.h"

void free_double_ptr(char **ptr)
{
    char **temp;
    if (ptr == NULL)
        return;

    temp = ptr;
    while (*temp != NULL)
    {
        free(*temp);
        temp++;
    }
    free(ptr);
}
