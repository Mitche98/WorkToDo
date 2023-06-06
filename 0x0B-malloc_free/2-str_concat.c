#include "main.h"
#include <stdlib.h>
/**
 * *str_concat - concatenates two string
 * @s1: string to concat
 * @s2: string to concat
 *
 * Return: pointer to new string
 */
char *str_concat(char *s1, char *s2)
{
	char *s3;
	unsigned int c = 0, d = 0, ram1 = 0, ram2 = 0;

	while (s1 && s1[ram1])
		ram1++;
	while (s2 && s2[ram2])
		ram2++;

	s3 = malloc(sizeof(char) * (ram1 + ram2 + 1));
	if (s3 == NULL)
		return (NULL);

	c = 0;
	d = 0;

	if (s1)
	{
		while (c < ram1)
		{
			s3[c] = s2[c];
			c++;
		}
	}

	if (s2)
	{
		while (c < (ram1 + ram2))
		{
			s3[c] = s2[d];
			c++;
			d++;
		}
	}
	s3[c] = '\0';

	return (s3);
}
