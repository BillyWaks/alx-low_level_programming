#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
#include <strings.h>

/**
 * get_nodeint_at_index - returns the node at a certain index in a linked list
 * @head: pointer to the first element in the list
 * @index: index of the node to return
 *
 * Return: 0 when success, NULL when it fails
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	/* initialization */
	unsigned int num = 0;

	listint_t *node = head;

	while (num < index && node)
	{
		node = node->next;
		num++;
	}

	return (node ? node : NULL);
}

