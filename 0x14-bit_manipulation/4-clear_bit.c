#include "main.h"

/**
 * clear_bit - sets value of bit to 0 at given index
 * @n: pointer of unsigned long int
 * @index: index of bit
 *
 * Return: 1 if success, otherwise -1
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int f;

	if (index > 63)
		return (-1);

	f = 1 << index;

	if (*n & f)
		*n ^= f;

	return (1);
}
