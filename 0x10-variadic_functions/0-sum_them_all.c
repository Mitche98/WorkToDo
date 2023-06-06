#include "variadic_functions.h"
#include <stdarg.h>
/**
 * sum_them_all - adds all numbers
 * @n: number of parameters
 *
 * Return: Always 0
 */
int sum_them_all(const unsigned int n, ...)
{
	int sum;
	unsigned int a;
	va_list mos;

	va_start(mos, n);

	if (n == 0)
		return (0);

	for (a = 0; a < n; a++)
		sum += va_arg(mos, int);

	va_end(mos);

	return (sum);
}
