#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_strings - prints string followed by a new line
 * @separator: string to be printed between strings
 * @n: number of strings passed to function
 * @...: variable number of strings
 *
 * Return: NULL if not printed, (nil) is printed otherwise
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list strings;
	char *bec;
	unsigned int tribe;

	va_start(strings, n);

	for (tribe = 0; tribe < n; tribe++)
	{
		bec = va_arg(strings, char *);

		if (bec == NULL)
			printf("(nil)");
		else
			printf("%s", bec);

		if (tribe != (n - 1) && separator != NULL)
			printf("%s", separator);
	}

	printf("\n");

	va_end(strings);
}
