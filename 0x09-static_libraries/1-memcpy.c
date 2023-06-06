#include "main.h"
/**
 * _memcpy - function that copies memory area
 * @dest: memory where stored
 * @src: memory where copied
 * @n: number of bytes
 *
 * Return: copied memory with changed n byte
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	int c = 0;
	int d = n;

	for (; c < d; c++)
	{
		dest[c] = src[c];
		n--;
	}

	return (dest);
}
