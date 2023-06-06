#include "main.h"
/**
 * flip_bits - returns numeber of bits needed to flip and
 * get one from another
 * @n: number one
 * @m: number two
 *
 * Return: number of bits
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int bit_num;

	for (bit_num = 0; n || m; n >>= 1, m >>= 1)
	{
		if ((n & 1) != (m & 1))
			bit_num++;
	}

	return (bit_num);
}
