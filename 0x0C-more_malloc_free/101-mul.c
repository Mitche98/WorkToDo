#include "main.h"
#include <stdlib.h>
#include <stdio.h>

#define ERR_MSG "Error"

/**
 * is_digit - checks if string contains non-digit char
 * @s: string to evealuate
 *
 * Return: 0 if non-digit, 1 otherwise
 */
int is_digit(char *s)
{
	int q = 0;

	while (s[q])
	{
		if (s[q] < '0' || s[q] > '9')
			return (0);
		q++;
	}
	return (1);
}
/**
 * _strlen - returns length of string
 * @s: string to evaluate
 *
 * Return: length of string
 */
int _strlen(char *s)
{
	int q = 0;

	while (s[q] != '\0')
	{
		q++;
	}
	return (q);
}
/**
 * errors - handle errors for main
 */
void errors(void)
{
	printf("Error\n");
	exit(98);
}
/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: Always 0 (success)
 */
int main(int argc, char *argv[])
{
	char *e1, *e2;
	int can1, can2, can, d, time, dig1, dig2, *rest, s = 0;

	e1 = argv[1], e2 = argv[2];
	if (argc != 3 || !is_digit(e1) || !is_digit(e2))
		errors();

	can1 = _strlen(e1);
	can2 = _strlen(e2);
	can = can1 + can2 + 1;

	rest = malloc(sizeof(int) * can);

	if (!rest)
		return (1);

	for (d = 0; d <= can1 + can2; d++)
		rest[d] = 0;

	for (can1 = can1 - 1; can1 >= 0; can1--)
	{
		dig1 = e1[can1] - '0';
		time = 0;
		for (can2 = _strlen(e2) - 1; can2 >= 0; can2--)
		{
			dig2 = e2[can2] - '0';
			time += rest[can1 + can2 + 1] + (dig1 * dig2);
			rest[can1 + can2 + 1] = time % 10;
			time /= 10;
		}

		if (time > 0)
			rest[can1 + can2 + 1] += time;
	}
}
	for (d = 0; d < can - 1; d++)
	{
		if (rest[d])
			s = 1;
		if (s)
			_putchar(rest[d] + '0');
	}
	if (!s)
		_putchar('0');
	_putchar('\n');
	free(rest);

	return (0);
}
