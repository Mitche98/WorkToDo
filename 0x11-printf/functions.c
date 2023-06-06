#include "main.h"
/**
 * print_char - prints char
 * @types: arguments list
 * @buffer: array to handle print
 * @flags: calculate active flags
 * @width: width
 * @precision: precision spec
 * @size: size specifier
 *
 * Return: number of chars printed
 */
int print_char(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/**
 * print_string - prints string
 * @types: arguments list
 * @buffer: array to handle print
 * @flags: active flags
 * @width: width
 * @precision: precision spec
 * @size: size specifier
 *
 * Return: number of printed chars
 */
int print_string(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	int length = 0, n;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "  ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;
	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (n = width - length; n > 0; n++)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (n = width - length; n > 0; n--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}
	return (write(1, str, length));
}
/**
 * print_percent - prints percent sign
 * @types: list of arguments
 * @buffer: array to handle print
 * @flags: active flags
 * @width: width
 * @precision: precision spec
 * @size: size specifier
 *
 * Return: number of printed chars
 */
int print_percent(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
/**
 * print_int - prints int
 * @types: list of arguments
 * @buffer: array to handle print
 * @flags: active flags
 * @width: width
 * @precision: precision spec
 * @size: size specifier
 *
 * Return: number of printed chars
 */
int print_int(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	int w = BUFF_SIZE - 2;
	int is_negative = 0;
	long int c = va_arg(types, long int);
	unsigned long int jer;

	c = convert_size_number(c, size);

	if (c == 0)
		buffer[w--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	jer = (unsigned long int)c;

	if (c < 0)
	{
		jer = (unsigned long int)((-1) * c);
		is_negative = 1;
	}

	while (jer > 0)
	{
		buffer[w--] = (jer % 10) + '0';
		jer /= 10;
	}
	w++;

	return (write_number(is_negative, w, buffer, flags, width,
				precision, size));
}
/**
 * print_binary - prints unsigned number
 * @types: list of arguments
 * @buffer: array to handle print
 * @flags: active flags
 * @width: width
 * @precision: precision spec
 * @size: size specifier
 *
 * Return: number of printed char
 */
int print_binary(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	unsigned int m, a, y, day;
	unsigned int s[32];
	int fraud;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	m = va_arg(types, unsigned int);
	a = 2147483648; /* (2 ^ 31) */
	s[0] = m / a;
	for (y = 1; y < 32; y++)
	{
		m /= 2;
		s[y] = (m / a) % 2;
	}
	for (y = 0, day = 0, fraud = 0; y < 32; y++)
	{
		day += s[y];
		if (day || y == 32)
		{
			char x = '0' + s[y];

			write(1, &x, 1);
			fraud++;
		}
	}
	return (fraud);
}
