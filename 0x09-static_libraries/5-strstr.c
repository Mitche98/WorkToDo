#include "main.h"
/**
 * _strstr - entry point
 * @haystack: input
 * @needle: input
 *
 * Return: Always 0
 */
char *_strstr(char *haystack, char *needle)
{
	for (; *haystack != '\0'; haystack++)
	{
		char *y = haystack;
		char *h = needle;

		while (*y == *h && *y != '\0')
		{
			y++;
			h++;
		}

		if (*h == '\0')
			return (haystack);
	}

	return (0);
}
