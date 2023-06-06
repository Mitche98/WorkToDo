#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * add_node - adds new node at beginning of list
 * @head: original linked list
 * @str: string to add node
 *
 * Return: address of new list, NULL if failed
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *type;

	if (head != NULL && str != NULL)
	{
		type = malloc(sizeof(list_t));
		if (type == NULL)
			return (NULL);

		type->str = strdup(str);
		type->len = _strlen(str);
		type->next = *head;

		*head = type;

		return (type);
	}

	return (0);
}

/**
 * _strlen - returns length of a string
 * @s: string to count
 *
 * Return: string length
 */
int _strlen(const char *s)
{
	int l = 0;

	while (*s)
	{
		s++;
		l++;
	}

	return (l);
}
