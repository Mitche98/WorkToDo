#include "lists.h"
/**
 * add_nodeint_end - adds new node at end of listint_t list
 * @head: pointer to address of head of listint_t list
 * @n: integer for new node to contain
 *
 * Return: NULL if function fails, otherwise address of new element
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *you, *best;

	you = malloc(sizeof(listint_t));
	if (you == NULL)
		return (NULL);

	you->n = n;
	you->next = NULL;

	if (*head == NULL)
		*head = you;

	else
	{
		best = *head;
		while (best->next != NULL)
			best = best->next;
		best->next = you;
	}

	return (*head);
}
