#include "main.h"
#include <stdlib.h>
/**
 * _calloc - allocates memory for an array
 * @nmemb: number of elements
 * @size: size of bytes
 *
 * Return: pointer to allocated memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *w;
	unsigned int g;

	if (nmemb == 0 || size == 0)
		return (NULL);
	w = malloc(nmemb * size);

	if (a == NULL)
		return (NULL);
	for (g = 0; g < (nmemb * size); g++)
		w[g] = 0;

	return (w);
}
