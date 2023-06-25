#include "main.h"

void* re_alloc(void* ptr, size_t size);


ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
	size_t position = 0;
    int eof = 0;
    char c;
    char *tmp;
    ssize_t numbyt_read;

    if (*lineptr == NULL && *n == 0)
    {
        *n = 1;
        *lineptr = malloc(sizeof(char) * (*n + 1));
        if (*lineptr == NULL)
            return (-1);
    }
    while (!eof)
    {
        numbyt_read = read(fileno(stream), &c, 1);
        if (numbyt_read <= 0)
        {
            break;
        }

        if (position >= (*n -1))
        {
            *n *= 2;
            tmp = re_alloc(*lineptr, sizeof(char) * (*n + 1));
            if (tmp == NULL)
            {
                return (-1);
            }
            *lineptr = tmp;
        }
        (*lineptr)[position++] = c;
        if (c == '\n')
        {
            break;
        }
    }
    if (position == 0)
        return (-1);

    (*lineptr)[position] = '\0';
	    return (position);
}
