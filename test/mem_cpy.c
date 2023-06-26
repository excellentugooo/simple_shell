#include "main.h"

/**
 *mem_cpy -  copies memory area
 *@dest: destination
 *@src: source
 *@n: bytes
 *Return: dest
 */

char *mem_cpy(char *dest, char *src, unsigned int n)
{
	int a = 0;
	int b = n;

	for (; a < b; a++)
	{
		dest[a] = src[a];
		n--;
	}
	return (dest);
}
