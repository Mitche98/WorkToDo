#include "main.h"
/**
 * get_width - calculates width for printing
 * @format: formatted string to print argument
 * @i: list of arguments to be printed
 * @list: list of arguments
 *
 * Return: width
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_g;
	int width = 0;

	for (curr_g = *i + 1; format[curr_g] != '\0'; curr_g++)
	{
		if (is_digit(format[curr_g]))
		{
			width *= 10;
			width += format[curr_g] - '0';
		}
		else if (format[curr_g] == '*')
		{
			curr_g++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_g - 1;

	return (width);
}
