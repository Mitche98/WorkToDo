#include "lists.h"

/**
 * add_dnodeint - adds new node at beginning of dlistint list
 * @head: head of list
 * @n: value of element
 *
 * Return: address of new element
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *bad;
	dlistint_t *g;

	bad = malloc(sizeof(dlistint_t));
	if (bad == NULL)
		return (NULL);

	bad->n = n;
	bad->prev = NULL;
	g = *head;

	if (g != NULL)
	{
		while (g->prev != NULL)
			g = g->prev;
	}

	bad->next = g;

	if (g != NULL)
		g->prev = bad;

	*head = bad;

	return (bad);
}
