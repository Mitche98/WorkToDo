#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * list_len - shows number of list elements
 * @h: linked list
 *
 * Return: number of list elements
 */
size_t list_len(const list_t *h)
{
	size_t find = 0;

	while (h)
	{
		h = h->next;
		find++
	}

	return (find);
}
