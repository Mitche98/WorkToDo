#include "main.h"
#include <stdlib.h>
/**
 * *malloc_checked - allocates memory using malloc
 * @b: number of bytes to allocate
 *
 * Return: pointer to allocated memory
 */
void *malloc_checked(unsigned int b);
{
	int *try;

	try = malloc(b);

	if (try == NULL)
		exit(98);

	return (try);
}
