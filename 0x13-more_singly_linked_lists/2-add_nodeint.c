#include "lists.h"

/**
 * add_nodeint - adds a new node at beginning of listint_t list
 * @head: pointer to address of head of lsitint_t list
 * @n: integer for new node to contain
 *
 * Return: NULL if function fails, otherwise address of new element
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *set;

	set = malloc(sizeof(listint_t));
	if (set == NULL)
		return (NULL);

	set->n = n;
	set->next = *head;

	*head = set;

	return (new);
}
