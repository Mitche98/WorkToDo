#include "lists.h"
/**
 * delete_nodeint_at_index - deletes node at given index if
 * listint_t list
 * @head: pointer to address of listint_t list
 * @index: index of node to be deleted
 *
 * Return: on success 1, otherwise -1
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *hit, *font = *head;
	unsigned int node;

	if (font == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(font);
		return (1);
	}

	for (node = 0; node < (index - 1); node++)
	{
		if (font->next == NULL)
			return (-1);

		font = font->next;
	}

	hit = font->next;
	font->next = hit->next;
	free(hit);
	return (1);
}
