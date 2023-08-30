#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
#include <strings.h>

/**
 * pop_listint - deletes the head node of a linked list,
 * returns the head node’s data (n).
 *
 * @head: pointer to the head
 *
 * Return: 0 when the linked list is empty
 */

int pop_listint(listint_t **head)
{
	listint_t *node;
	int m;

	if (!head || !*head)
		return (0);

	m = (*head)->n;
	node = (*head)->next;
	free(*head); /*deletes the head node*/

	*head = node;

	return (m);
}

