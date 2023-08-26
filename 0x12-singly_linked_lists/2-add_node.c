#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lists.h"

/**
 * *add_node - adds a new node at the beginning of a linked list
 * @str: new string to add to a node
 * @head: double pointer to the linked file list_t list
 *
 * Return: the address of the new element / NULL when it fails
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *new = malloc(sizeof(list_t));

	if (new == NULL)

		return (NULL);

	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}

	new->len = strlen(str);
	new->next = *head;
	*head = new;

	return (new);
}
