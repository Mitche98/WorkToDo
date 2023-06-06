#include "main.h"
/**
 * get_size - calculates size to cast argument
 * @format: formatted string to print arguments
 * @i: list of arguments to be printed
 *
 * Return: size
 */
int get_size(const char *format, int *i)
{
	int curr_g = *i + 1;
	int size = 0;

	if (format[curr_g] == 'l')
		size = S_LONG;
	else if (format[curr_g] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curr_g - 1;
	else
		*i = curr_g;

	return (size);
}
