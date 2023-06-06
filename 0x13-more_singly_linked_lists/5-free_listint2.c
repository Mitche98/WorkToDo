#include "lists.h"

/**
 * free_listint2 - frees a listint_t list
 * @head: pointer to address of head of listint_t list
 */
void free_listint2(listint_t **head)
{
	listint_t *dax;

	if (head == NULL)
		return;

	while (*head)
	{
		dax = (*head)->next;
		free(*head);
		*head = dax;
	}

	head = NULL;
}
