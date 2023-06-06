#include <stdio.h>
#include "main.h"

/**
 * _putchar - writes char to stdout
 * @c: char to print
 *
 * Return: on success 1,
 * on error -1 is returned
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
