#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * *add_node_end - adds a new node at the end of a linked list.
 * @head: double pointer to list_t list
 * @str: string to put in the new node
 *
 * Return: the address of the new element, or NULL if it fails
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new, *current;

	list_t *new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	if (new->str)
	{
		free(new);
		return (NULL);
	}

	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
	}
	else
	{
		list_t *current = *head;

		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}

	return (new);
}
