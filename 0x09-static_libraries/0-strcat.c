#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: input value
 * @src: input value
 *
 * Return: void
 */
char *_strcat(char *dest, char *src)
{
	int l;
	int p;

	l = 0;
	while (dest[l] != '\0')
	{
		l++;
	}
	p = 0;
	while (src[p] != '\0')
	{
		dest[l] = src[p];
		l++;
		p++;
	}

	dest[l] = '\0';
	return (dest);
}
