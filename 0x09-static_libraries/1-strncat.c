#include "main.h"
/**
 * _strncat - concatenates two strings using
 * at most n bytes from src
 * @dest: input value
 * @src: input value
 * @n: input
 *
 * Return: dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int s;
	int k;

	s = 0;
	while (dest[s] != '\0')
	{
		s++;
	}
	k = 0;
	while (k < n && src[k] != '\0')
	{
		dest[s] = src[k];
		s++;
		k++;
	}
	dest[s] = '\0';
	return (dest);
}
