#include "main.h"
#include <stdlib.h>
/**
 * **alloc_grid -creates two dimensional array if ints
 * @width: width
 * @height: height
 *
 * Return: pointer to created matrix or NULL
 */
int **alloc_grid(int width, int height)
{
	int **array;
	int n, x;

	if (height <= 0 || width <= 0)
		return (NULL);

	array = (int **) malloc(sizeof(int *) * height);

	if (array == NULL)
		return (NULL);
	for (n = 0; n < height; n++)
	{
		array[n] = (int *) malloc(sizeof(int) * width);
		if (array[n] == NULL)
		{
			free(array);
			for (x = 0; x <= n; x++)
				free(array[x]);
			return (NULL);
		}
	}

	for (n = 0; n < height; n++)
	{
		for (x = 0; x < width; x++)
		{
			array[n][x] = 0;
		}
	}
	return (array);
}
