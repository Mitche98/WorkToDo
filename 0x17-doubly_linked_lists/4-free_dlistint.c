#include "lists.h"

/**
 * free_dlistint - frees dlistint_t list
 * @head: head of list
 *
 * Return: no return
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *yet;

	if (head != NULL)
		while (head->prev != NULL)
			head = head->prev;

	while ((yet = head) != NULL)
	{
		head = head->next;
		free(yet);
	}
}
