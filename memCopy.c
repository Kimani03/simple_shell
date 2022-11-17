#include "shell.h"

/**
 * _memCopy - function that copies memory area
 * @dest: destination of memory area
 * @src: source of the memory area
 * @n: copies n bytes
 * Return: returns a pointer to the destination
 */

char *_memCopy(char *dest, char *src, unsigned int n)
{
	unsigned int a;

	for (a = 0; a < n; a++)
		dest[a] = src[a];
	return (dest);
}

