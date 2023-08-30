#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
#include <strings.h>

/**
 * free_listint2 - function that frees a listint_t list
 * @head: double pointer to the head
 *
 * The function sets the head to NULL
 */

void free_listint2(listint_t **head)
{
	listint_t *node;

	if (head == NULL)
		return;

	while (*head)
	{
		node = (*head)->next;
		free(*head);
		*head = node;
	}

	*head = NULL;
}

