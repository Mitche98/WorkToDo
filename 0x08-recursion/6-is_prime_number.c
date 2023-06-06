#include "main.h"
/**
 * check - to see if num is prime
 * @b: int
 * @k: int
 *
 * Return: int
 */
int check(int b, int k)
{
	if (k < 2 || k % b == 0)
		return (0);

	else if (b > k / 2)
		return (1);

	else
		return (check(b + 1, k));
}

/**
 * is_prime_number - returns 1 if input int is prime num
 * @n: int to check
 *
 * Return: int
 */
int is_prime_number(int n)
{
	if (n == 2)
		return (1);
	return (check(2, n));
}
