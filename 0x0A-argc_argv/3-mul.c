#include <stdio.h>
#include "main.h"

/**
 * _atoi - converts string to int
 * @s: string to be converted
 *
 * Return: int converted from string
 */
int _atoi(char *s)
{
	int m, j, a, try, r, trust;

	m = 0;
	j = 0;
	a = 0;
	try = 0;
	r = 0;
	trust = 0;

	while (s[try] != '\0')
		try++;

	while (m < try && r == 0)
	{
		if (s[m] == '-')
			++j;

		if (s[m] >= '0' && s[m] <= '9')
		{
			trust = s[m] - '0';
			if (j % 2)
				trust = -trust;
			a = a * 10 + trust;
			r = 1;
			if (s[m + 1] < '0' || s[m + 1] > '9')
				break;
			r = 0;
		}
		m++;
	}

	if (r == 0)
		return (0);

	return (a);
}

/**
 * main - multiplies two numbers
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 (success), 1 (error)
 */
int main(int argc, char *argv[])
{
	int source, rem1, rem2;

	if (argc < 3 || argc > 3)
	{
		printf("Error\n");
		return (1);
	}

	rem1 = _atoi(argv[1]);
	rem2 = _atoi(argv[2]);
	source = rem1 * rem2;

	printf("%d\n", source);

	return (0);
}
