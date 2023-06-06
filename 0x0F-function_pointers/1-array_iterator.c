#include "function_pointers.h"
#include <stdio.h>

/**
 * array_iterator - prints each array element
 * @array: array
 * @size: size of element
 * @action: pointer to print in hex
 *
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t j;

	if (array && action)
	{
		j = 0;

		while (j < size)
		{
			action(array[j]);
			j++;
		}
	}
}
