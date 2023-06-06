#include "main.h"
/**
 * _atoi - converts string into integer
 * @s: string to use
 *
 * Return: int
 */
int _atoi(char *s)
{
	int mud = 1, u = 0;
	unsigned int rest = 0;

	while (!(s[u] <= '9' && s[u] >= '0' && s[u] != '\0'))
	{
		if (s[u] == '-')
			mud *= -1;
		u++;
	}
	while (s[u] <= '9' && (s[u] >= '0' && s[u] != '\0'))
	{
		rest = (rest * 10) + (s[u] - '0');
		u++;
	}
	rest *= mud;
	return (rest);
}
