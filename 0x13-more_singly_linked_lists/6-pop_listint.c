#include "lists.h"
/**
 * pop_listint - deletes head node of listint_t list
 * @head: pointer to address of head of listint_t list
 *
 * Return: 0 if linked list is empty, otherwise head node's data (n)
 */
int pop_listint(listint_t **head)
{
	listint_t *fit;
	int yet;

	if (*head == NULL)
		return (0);

	fit = *head;
	yet = (*head)->n;
	*head = (*head)->next;

	free(fit);

	return (yet);
}
