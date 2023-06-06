#include "lists.h"
#include <stdio.h>

/**
 * listint_len - returns number of elements in linked listint_t list
 * @h: pointer to head of listint_t list
 *
 * Return: number of elements in listint_t list
 */
size_t listint_len(const listint_t *h)
{
	size_t nodes = 0;

	while (h)
	{
		nodes++;
		h = h->next;
	}

	return (nodes);
}
