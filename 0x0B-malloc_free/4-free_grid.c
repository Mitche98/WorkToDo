#include "main.h"
#include <stdlib.h>

/**
 * free_grid - frees memory allocated for grid created
 * by alloc_grid()
 * @grid: grid to free
 * @height: height of grid
 */
void free_grid(int **grid, int height)
{
	int d;

	if (grid == NULL || height == 0)
		return;

	for (d = 0; d < height; d++)
		free(grid[d]);

	free(grid);
}
