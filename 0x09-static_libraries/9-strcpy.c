#include "main.h"

/**
 * char *_strcpy - function that copies string pointed to by src
 * @dest: copy to
 * @src: copy from
 *
 * Return: string
 */
char *_strcpy(char *dest, char *src)
{
	int m = 0;
	int e = 0;

	while (*(src + m) != '\0')
	{
		m++;
	}
	for (; e < m; e++)
	{
		dest[e] = src[e];
	}
	dest[m] = '\0';
	return (dest);
}
