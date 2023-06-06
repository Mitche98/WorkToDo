#include "main.h"
/**
 * factorial - returns factorial
 * @n: int to be checked
 *
 * Return: -1 if n is < 0 or int
 */
int factorial(int n)
{
	int b;

	if (n == 0)
	{
		return (1);
	}
	else if (n < 0)
	{
		return (-1);
	}
	else
	{
		b = n * factorial(n - 1);
	}

	return (b);
}
