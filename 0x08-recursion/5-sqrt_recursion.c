#include "main.h"
/**
 * check - for square root
 * @j: int
 * @v: int
 *
 * Return: int
 */
int check(int j, int v)
{
	if (j * j == v)
		return (j);

	if (j * j > v)
		return (-1);

	return (check(j + 1, v));
}

/**
 * _sqrt_recursion - returns natural square root of a number
 * @n: int to find sqrt of
 *
 * Return: int or natural root or (-1)
 */

int _sqrt_recursion(int n)
{
	if (n == 0)
		return (0);
	return (check(1, n));
}
