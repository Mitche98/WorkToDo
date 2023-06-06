#include "lists.h"

/**
 * dlistint_len - returns number of elements in
 * doubly linked lists
 * @h: head of list
 *
 * Return: number of nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	int found;

	found = 0;

	if (h == NULL)
		return (found);

	while (h->prev != NULL)
		h = h->prev;

	while (h != NULL)
	{
		found++;
		h = h->next;
	}

	return (found);
}
