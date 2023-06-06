#include "lists.h"
/**
 * delete_dnodeint_at_index - deletes node at index of dlistint_t list
 * @head: head of list
 * @index: index of new node
 *
 * Return: 1 if successful, otherwise -1
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *ps1;
	dlistint_t *ps2;
	unsigned int xb;

	ps1 = *head;

	if (ps1 != NULL)
		while (ps1->prev != NULL)
			ps1 = ps1->prev;

	xb = 0;

	while (ps1 != NULL)
	{
		if (xb == index)
		{
			if (xb == 0)
			{
				*head = ps1->next;
				if (*head != NULL)
					(*head)->prev = NULL;
			}
			else
			{
				ps2->next = ps1->next;

				if (ps1->next != NULL)
					ps1->next->prev = ps2;
			}

			free(ps1);
			return (1);
		}
		ps2 = ps1;
		ps1 = ps1->next;
		xb++;
	}

	return (-1);
}
