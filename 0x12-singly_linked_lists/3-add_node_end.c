#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
#include <string.h>

/**
 * add_node_end - adds new node at end of a list
 * @head: original linked list
 * @str: string to add the node
 *
 * Return: address of new list, NULL otherwise
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_list, *type;

	if (str != NULL)
	{
		new_list = malloc(sizeof(list_t));
		if (new_list == NULL)
			return (NULL);

		new_list->str = strdup(str);
		new_list->len = _strlen(str);
		new_list->next = NULL;

		if (*head == NULL)
		{
			*head = new_list;
			return (*head);
		}
		else
		{
			type = *head;
			while (type->next)
				type = type->next;

			type->next = new_list;
			return (type);
		}
	}

	return (NULL);
}

/**
 * _strlen - returns length of a string
 * @s: string to count
 *
 * Return: string length
 */
int _strlen(const char *s)
{
	int d = 0;

	while (*s)
	{
		s++;
		d++;
	}

	return (d);
}
