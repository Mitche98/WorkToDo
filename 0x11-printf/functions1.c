#include "main.h"
/**
 * print_unsigned - prints unsigned number
 * @types: list of arguments
 * @buffer: array to handle print
 * @flags: active flags
 * @width: width
 * @precision: precision spec
 * @size: size specifier
 *
 * Return: number of printed chars
 */
int print_unsigned(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	int c = BUFF_SIZE - 2;
	unsigned long int tom = va_arg(types, unsigned long int);

	tom = convert_size_unsgnd(tom, size);

	if (tom == 0)
		buffer[c--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (tom > 0)
	{
		buffer[c--] = (tom % 10) + '0';
		tom /= 10;
	}

	c++;

	return (write_unsgnd(0, c, buffer, flags, width, precision, size));
}
/**
 * print_octal - prints unsigned number in octal notation
 * @types: list of arguments
 * @buffer: array to handle print
 * @flags: active flags
 * @width: width
 * @precision: precision spec
 * @size: size specifier
 *
 * Return: number of printed chars
 */
int print_octal(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	int t = BUFF_SIZE - 2;
	unsigned long int cut = va_arg(types, unsigned long int);
	unsigned long int init_cut = cut;

	UNUSED(width);

	cut = convert_size_unsgnd(cut, size);

	if (cut == 0)
		buffer[t--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (cut > 0)
	{
		buffer[t--] = (cut % 8) + '0';
		cut /= 8;
	}

	if (flags & F_HASH && init_cut != 0)
		buffer[t--] = '0';

	t++;

	return (write_unsgnd(0, t, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - prints unsigned number in hexadecimal notation
 * @types: list of argument
 * @buffer: array to handle print
 * @flags: active flags
 * @width: width
 * @precision: precision spec
 * @size: size specifier
 *
 * Return: number of printed chars
 */
int print_hexadecimal(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer *, flags,
				'X', width, precision, size));
}

/**
 * print_hexa_upper - prints unsigned number in upper hexadec
 * @types: list of arguments
 * @buffer: array of arguments
 * @flags: active flags
 * @width: width
 * @precision: precision spec
 * @size: size specifier
 *
 * Return: number of printed chars
 */
int print_hexa_upper(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	return (print_hexa(types, buffer, "0123456789ABCDEF",
				flags, 'X', width, precision, size));
}

/**
 * print_hexa - prints hexadecimal in upper/lower
 * @types: list of argument
 * @buffer: array to handle print
 * @flags: active flags
 * @width: width
 * @precision: precision spec
 * @size: size specifier
 *
 * Return: number of printed chars
 */
int print_hexa(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	int m = BUFF_SIZE - 2;
	unsigned long int fat = va_arg(types, unsigned long int);
	unsigned long int init_fat = fat;

	UNUSED(width);

	fat = convert_size_unsgnd(fat, size);

	if (fat == 0)
		buffer[m--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (fat > 0)
	{
		buffer[m--] = map_to[fat % 16];
		fat /= 16;
	}

	if (flags & F_HASH && init_fat != 0)
	{
		buffer[m--] = flags_ch;
		buffer[m--] = '0';
	}
	m++;

	return (write_unsgnd(0, m, buffer, flags, width, precision, size));
}
