#include "variadic_functions.h"
#include <stdarg.h>

/**
 * print_number - prints numbers, followed by new line
 * @separator: string to be printed
 * @n: number of integers
 * @...: A variable number to be printed
 */
void print_number(const char *separator, const unsigned int n, ...)
{
	va_list gain;
	unsigned int index;

	va_start(gain, n);

	for (index = 0; index < n; index++)
	{
		printf("%d", va_arg(gain, int));

		if (index != (n - 1) && separator != NULL)
			printf("%s", separator);
	}

	printf("\n");

	va_end(gain);
}
