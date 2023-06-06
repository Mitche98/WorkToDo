#include "lists.h"

/**
 * reverse_listint - reverses listint_t list
 * @head: pointer to address of head of listint_t list
 *
 * Return: pointer to first node of reserved list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *over, *under;

	if (head == NULL || *head == NULL)
		return (NULL);

	under = NULL;

	while ((*head)->next != NULL)
	{
		over = (*head)->next;
		(*head)->next = under;
		under = *head;
		*head = over;
	}

	(*head)->next = under;

	return (*head);
}
