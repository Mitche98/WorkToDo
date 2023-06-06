#include "main.h"
/**
 * get_precision - calculates precision for printing
 * @format: formatted string to print arguments
 * @i: list of arguments to be printed
 * @list: list of arguments
 *
 * Return: precision
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr_g = *i + 1;
	int precision = -1;

	if (format[curr_g] != '.')
		return (precision);

	precision = 0;

	for (curr_g += 1; format[curr_g] != '\0'; curr_g++)
	{
		if (is_digit(format[curr_g]))
		{
			precision *= 10;
			precision += format[curr_g] - '0';
		}
		else if (format[curr_g] == '*')
		{
			curr_g++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_g - 1;

	return (precision);
}
