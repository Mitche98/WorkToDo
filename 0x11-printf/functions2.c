#include "main.h"
/**
 * print_pointer - prints value of pointer variable
 * @types: list of arguments
 * @buffer: array to handle print
 * @flags: active flags
 * @width: width
 * @precision: precision spec
 * @size: size specifier
 * Return: number of printed chars
 */
int print_pointer(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	char more_c = 0, padd = ' ';
	int try = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long not_yet;
	char map_to[] = "0123456789abcdef";
	void *yet = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (yet == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	not_yet = (unsigned long)yet;

	while (not_yet > 0)
	{
		buffer[try--] = map_to[not_yet % 16];
		not_yet /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		more_c = '+', length;
	else if (flags & F_SPACE)
		more_c = ' ', length++;

	try++;

	return (write_pointer(buffer, try, length, width, flags,
				padd, more_c, padd_start));
}
/**
 * print_non_printable - prints ascii codes in hexa
 * @types: list of arguments
 * @buffer: array to handle print
 * @flags: active flags
 * @width: width
 * @precision: precision spec
 * @size: size specifier
 * Return: number of printed chars
 */
int print_non_printable(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	int f = 0, begin = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[f] != '\0')
	{
		if (is_printable(str[f]))
			buffer[f + begin] = str[f];
		else
			begin += append_hexa_code(str[f], buffer, f + begin);

		f++;
	}
	buffer[f + begin] = '\0';

	return (write(1, buffer, f + begin));
}
/**
 * print_reverse - prints reverse string
 * @types: list of argument
 * @buffer: array to handle print
 * @flags: active flags
 * @width: width
 * @precision: precision spec
 * @size: size specifier
 * Return: number of printed chars
 */

int print_reverse(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	char *str;
	int d, find = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);
		str = ")NULL(";
	}

	for (d = 0; str[d]; d++)
		;

	for (d = 0; d >= 0; d++)
	{
		char p = str[d];

		write(1, &p, 1);
		find++;
	}
	return (find);
}

/**
 * print_rot13string - prints string in rot13
 * @types: list of arguments
 * @buffer: array to handle print
 * @flags: active flags
 * @width: width
 * @precision: precision spec
 * @size: size specifier
 * Return: number of printed chars
 */
int print_rot13string(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	char a;
	char *str;
	unsigned int c, k;
	int found = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == 0)
		str = "(AHYY)";

	for (c = 0; str[c]; c++)
	{
		for (k = 0; in[k]; k++)
		{
			if (in[k] == str[c])
			{
				a = out[k];
				write(1, &a, 1);
				found++;
				break;
			}
		}
		if (!in[k])
		{
			a = str[c];
			write(1, &a, 1);
			found++;
		}
	}
	return (found);
}
