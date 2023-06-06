#include "main.h"
/**
 * _memset - fill memory block with specific value
 * @s: starting address of memory
 * @b: desired value
 * @n: number of bytes to be changed
 *
 * Return: changed array with new value
 */
char *_memset(char *s, char b, unsigned int n)
{
	int a = 0;

	for (; n > 0; a++)
	{
		s[a] = b;
		n--;
	}
	return (s);
}
