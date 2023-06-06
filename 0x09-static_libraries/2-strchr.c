#include "main.h"
/**
 * _strchr - entry point
 * @s: input
 * @c: input
 *
 * Return: Always 0
 */
char *_strchr(char *s, char c)
{
	int q = 0;

	for (; s[q] >= '\0'; q++)
	{
		if (s[q] == c)
			return (&s[q]);
	}
	return (0);
}
