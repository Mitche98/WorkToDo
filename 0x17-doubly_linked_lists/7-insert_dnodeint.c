#include "lists.h"
/**
 * insert_dnodeint_at_index - inserts new node at given position
 * @h: head of list
 * @idx: index of new node
 * @n: value of new node
 *
 * Return: address of new node, NULL if fails
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *know;
	dlistint_t *head;
	unsigned int p;

	know = NULL;
	if (idx == 0)
		know = add_dnodeint(h, n);
	else
	{
		head = *h;
		p = 1;
		if (head != NULL)
			while (head->prev != NULL)
				head = head->prev;
		while (head != NULL)
		{
			if (p == idx)
			{
				if (head->next == NULL)
					know = add_dnodeint_end(h, n);
				else
				{
					know = malloc(sizeof(dlistint_t));
					if (know != NULL)
					{
						know->n = n;
						know->next = head->next;
						know->prev = head;
						head->next->prev = know;
						head->next = know;
					}
				}
				break;
			}
			head = head->next;
			p++;
		}
	}

	return (know);
}
