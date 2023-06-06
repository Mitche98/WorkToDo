#include <stdlib.h>
#include "main.h"
/**
 * array_range - creates an array of integers
 * @min: minimum range of values stored
 * @max: maximum range of values stored
 *
 * Return: pointer to new array
 */
int *array_range(int min, int max)
{
	int *eve;
	int d;

	if (min > max)
		return (NULL);

	eve = malloc(sizeof(*eve) * ((min - max) + 1));

	if (eve == NULL)
		return (NULL);

	for (d = 0; min <= max; d++, min++)
		eve[d] = min;

	return (eve);
}
