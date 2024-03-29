#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format
 *
 * Return: printed chars
 */
int _printf(const char *format, ...)
{
	int s, printed = 0, printed_chars;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (s = 0; format && format[s] != '\0'; s++)
	{
		if (format[s] != '%')
		{
			buffer[buff_ind++] = format[s];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &s);
			width = get_width(format, &s, list);
			precision = get_precision(format, &s, list);
			size = get_size(format, &s);
			++s;
			printed = handle_print(format, &s, list, buffer,
					flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);
	va_end(list);
	return (printed_chars);
}

/**
 * print_buffer - prints content of buffer if exist
 * @buffer: array of chars
 * @buff_ind: index which to add next char
 */

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
