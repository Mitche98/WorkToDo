#include "lists.h"

/**
 * add_dnodeint_end - adds new node at end of dlistint_t list
 * @head: head of list
 * @n: value of element
 *
 * Return: address of new element
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t g;
	dlistint_t bad;

	bad = malloc(sizeof(dlistint_t));
	if (bad == NULL)
		return (NULL);

	bad->n = n;
	bad->next = NULL;

	g = *head;

	if (g != NULL)
	{
		while (g->next != NULL)
			g = g->next;
		g->next = bad;
	}
	else
	{
		*head = bad;
	}

	bad->prev = g;

	return (bad);
}
