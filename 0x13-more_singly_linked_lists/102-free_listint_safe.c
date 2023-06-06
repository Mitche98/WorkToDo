#include "lists.h"

size_t looped_listint_count(listint_t *head);
size_t free_listint_safe(listint_t **h);

/**
 * looped_listint_count - counts number of unique nodes in
 * looped listint_t linked list
 * @head: pointer to head of listint_t to check
 *
 * Return: 0 if list not looped, otherwise number of unique
 * nodes int list
 */
size_t looped_listint_count(listint_t *head)
{
	listint_t *tortoise, *hare;
	size_t node = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	tortoise = head->next;
	hare = (head->next)->next;

	while (hare)
	{
		if (tortoise == hare)
		{
			tortoise = head;
			while (tortoise != hare)
			{
				node++;
				tortoise = tortoise->next;
				hare = hare->next;
			}

			tortoise = tortoise->next;
			while (tortoise != hare)
			{
				node++;
				tortoise = tortoise->next;
			}

			return (node);
		}

		tortoise = tortoise->next;
		hare = (hare->next)->next;
	}

	return (0);
}

/**
 * free_listint_safe - frees listint_t list safely
 * @h: pointer to address of head of listint_t list
 *
 * Return: size of list freed
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *run;
	size_t node, index;

	nodes = looped_listint_count(*h);

	if (node == 0)
	{
		for (; h != NULL && *h != NULL; node++)
		{
			run = (*h)->next;
			free(*h);
			*h = run;
		}
	}
	else
	{
		for (index = 0; index < node; index++)
		{
			run = (*h)->next;
			free(*h);
			*h = run;
		}

		*h = NULL;
	}

	h = NULL;

	return (node);
}
