#include "main.h"

/**
 * set_bit - sets value of bit to 1 at given index
 * @n: pointer of unsigned long int
 * @index: index of bit
 *
 * Return: 1 if successful, otherwise -1
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int v;

	if (index > 63)
		return (-1);

	v = 1 << index;
	*n = (*n | v);

	return (1);
}
