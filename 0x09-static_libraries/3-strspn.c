#include "main.h"
/**
 * _strspn - entry point
 * @s: input
 * @accept: input
 *
 * Return: Always 0
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int t = 0;
	int v;

	while (*s)
	{
		for (v = 0; accept[v]; v++)
		{
			if (*s == accept[v])
			{
				t++;
				break;
			}
			else if (accept[v + 1] == '\0')
				return (t);
		}
		s++;
	}
	return (t);
}
