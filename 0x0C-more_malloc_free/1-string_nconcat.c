#include "main.h"
#include <stdlib.h>
/**
 * *string_nconcat - concatenates n bytes of string to another string
 * @s1: string to append
 * @s2: string to concatenate from
 * @n: number of total bytes
 *
 * Return: pointer to resulting string
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *s;
	unsigned int f, c, k;

	if (s1 == NULL)
	{
		f = 0;
	}
	else
	{
		for (f = 0; s1[f]; ++f)
			;
	}
	if (s2 == NULL)
	{
		c = 0;
	}
	else
	{
		for (c = 0; s2[c]; ++c)
			;
	}
	if (c > n)
		c = n;
	s = malloc(sizeof(char) * (f + c + 1));
	if (s == NULL)
		return (NULL);
	for (k = 0; k < f; k++)
		s[k] = s1[k];
	for (k = 0; k < c; k++)
		s[k + f] = s2[k];
	s[f + c] = '\0';

	return (s);
}
