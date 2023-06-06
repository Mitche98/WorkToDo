#include <stdlib.h>
#include "main.h"

/**
 * free_list - frees a linked list
 * @head: pointer to first node of list
 *
 * Return: Nothing
 */
void free_list(list_t *head)
{
	list_t *test;

	while (head)
	{
		test = head;
		head = head->next;
		free(test->str);
		free(test);
	}

	free(head);
}
