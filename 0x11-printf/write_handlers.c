#include "main.h"
/**
 * handle_write_char - prints a string
 * @c: char types
 * @buffer: array to handle print
 * @flags: calculates active flags
 * @width: width
 * @precision: precision spec
 * @size: size specifier
 * Return: number of printed chars
 */
int handle_write_char(char c, char buffer[], int flags, int width,
		int precision, int size)
{
	int w = 0;
	char padd = '';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';

	buffer[w++] = c;
	buffer[w] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (w = 0; w < width - 1; w++)
			buffer[BUFF_SIZE - w - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - w - 1],
						width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - w - 1],
						width - 1) + write(1,
							&buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}
/**
 * write_number - prints string
 * @is_negative: list of argument
 * @ind: char types
 * @buffer: array to handle print
 * @flags: calculates active flags
 * @width: width
 * @precision: precision spec
 * @size: size specifier
 * Return: number of printed chars
 */
int write_number(int is_negative, int ind, char buffer[], int flags,
		int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags, width, precision,
				length, padd, extra_ch));
}
/**
 * write_num - writes number using buffer
 * @ind: index which number starts on buffer
 * @buffer: buffer
 * @flags: active flags
 * @width: width
 * @prec: precision spec
 * @length: number length
 * @padd: padding char
 * @extra_c: extra char
 * Return: number of printed chars
 */
int write_num(int ind, char buffer[], int flags, int width, int prec,
		int length, char padd, char extra_c)
{
	int u, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0'
			&& width == 0)
		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' ';
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
}
	if (width > length)
	{
		for (u = 1; u < width - length + 1; u++)
			buffer[u] = padd;
		buffer[u] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) +
					write(1, &buffer[1], u - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], u - 1) + write(1,
						&buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], u - padd_start)
					+ write(1, &buffer[ind], length -
						(1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}
/**
 * write_unsgnd - writes unsigned number
 * @is_negative: number indication if its negative
 * @ind: index which number starts
 * @buffer: array of chars
 * @flags: active flags
 * @width: width
 * @precision: precision spec
 * @size: size specifier
 * Return: number of printed chars
 */
int write_unsgnd(int is_negative, int ind, char buffer[], int flags,
		int width, int precision, int size)
{
	int length = BUFF_SIZE - 1, e = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);
	if (precision > 0 && precision < length)
		padd = ' ';
	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';

	if (width > length)
	{
		for (e = 0; e < width - length; e++)
			buffer[e] = padd;

		buffer[e] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], length) + write
					(1, &buffer[0], e));
		}
		else
		{
			return (write(1, &buffer[0], e) + write(1,
						&buffer[ind], length));
		}
	}

	return (write(1, &buffer[ind], length));
}

/**
 * write_pointer - writes a memory address
 * @buffer: arrays of char
 * @ind: index where number starts in buffer
 * @length: length of number
 * @width: width
 * @flags: active flags
 * @padd: padding char
 * @extra_c: extra char
 * @padd_start: index which padding starts
 *
 * Return: number of written chars
 */
int write_pointer(char buffer[], int ind, int length, int width,
		int flags, char padd, char extra_c, int padd_start)
{
	int v;

	if (width > length)
	{
		for (v = 3; v < width - length + 3; v++)
			buffer[v] = padd;
		buffer[v] = '\0';

		if (flags & F_MINUS && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) +
					write(1, &buffer[3], v - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], v - 3) +
					write(1, &buffer[ind], length));
		}
		else if
		{
			if (extra_c)
				buffer[-padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], v - padd_start) +
					write(1, &buffer[ind], length -
						(1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
