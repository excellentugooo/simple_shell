#include <stdio.h>
#include <stdlib.h>

ssize_t getline(char **lineptr, size_t *n, FILE *stream) {
    if (lineptr == NULL || n == NULL || stream == NULL) {
        return -1;
    }

    // Set the initial buffer size if not provided
    if (*lineptr == NULL || *n == 0) {
        *n = 128;
        *lineptr = malloc(*n);
        if (*lineptr == NULL) {
            return -1;
        }
    }

    char *buffer = *lineptr;
    size_t size = *n;
    size_t pos = 0;
    int c;

    while ((c = fgetc(stream)) != EOF) {
        if (pos >= size - 1) {
            // Expand the buffer size if needed
            size *= 2;
            char *new_buffer = realloc(buffer, size);
            if (new_buffer == NULL) {
                return -1;
            }
            buffer = new_buffer;
            *lineptr = buffer;
            *n = size;
        }

        buffer[pos++] = c;

        if (c == '\n') {
            break;
        }
    }

    // Add null terminator to the end of the line
    buffer[pos] = '\0';

    if (pos == 0 && c == EOF) {
        return -1;  // No characters read
    }

    return pos;
}

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

ssize_t custom_getline(char **lineptr, size_t *n) {
    if (lineptr == NULL || n == NULL) {
        return -1;
    }

    ssize_t bytesRead = 0;
    size_t bufferSize = BUFFER_SIZE;
    char *buffer = (char *) malloc(bufferSize);
    if (buffer == NULL) {
        return -1;
    }

    ssize_t result;
    size_t i = 0;
    char c;
    while ((result = read(0, &c, 1)) > 0 && c != '\n') {
        if (i == bufferSize - 1) {
            bufferSize += BUFFER_SIZE;
            char *newBuffer = (char *) realloc(buffer, bufferSize);
            if (newBuffer == NULL) {
                free(buffer);
                return -1;
            }
            buffer = newBuffer;
        }
        buffer[i++] = c;
    }

    if (result == -1) {
        free(buffer);
        return -1;
    }

    buffer[i] = '\0';
    *lineptr = buffer;
    *n = bufferSize;

    return i;
}

int main() {
    char *line = NULL;
    size_t len = 0;

    printf("Enter a line of text: ");
    ssize_t bytesRead = custom_getline(&line, &len);
    if (bytesRead == -1) {
        printf("Failed to read input.\n");
        return 1;
    }

    printf("Input line: %s\n", line);

    free(line);
    return 0;
}
