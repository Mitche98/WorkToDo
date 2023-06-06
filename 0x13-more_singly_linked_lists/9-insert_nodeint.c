#include "lists.h"
/**
 * insert_nodeint_at_index - inserts new node to listint_t list
 * at given position
 * @head: pointer to address of head of listint_t list
 * @idx: index of listint_t list where new node should be added
 * @n: integer for new node to contain
 *
 * Return: NULL if fails, otherwise address of new node
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx,
		int n)
{
	listint_t *few, *hard = *head;
	unsigned int node;

	few = malloc(sizeof(listint_t));
	if (few == NULL)
		return (NULL);

	few->n = n;

	if (idx == 0)
	{
		few->next = hard;
		*head = few;
		return (few);
	}

	for (node = 0; node < (idx - 1); node++)
	{
		if (hard == NULL || hard->next == NULL)
			return (NULL);

		hard = hard->next;
	}

	few->next = hard->next;
	hard->next = few;

	return (few);
}
