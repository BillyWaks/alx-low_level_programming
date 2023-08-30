#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
#include <strings.h>

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: double pointer to the first element in the list
 * @idx: where the new node is added (index)
 * @n: data to insert in the new node
 *
 * Return: the address of the new node, or NULL if it failed
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *current = *head;

	listint_t *new_node;

	unsigned int m;

	new_node = malloc(sizeof(listint_t));
	/*return NULL if the new node is not equivalent to the head*/
	if (!new_node || !head)
		return (NULL);
	/*inialization of new node pointer to n*/
	new_node->n = n;
	new_node->next = NULL;

	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	for (m = 0; current && m < idx; m++)
	{
		if (m == idx - 1)
		{
			new_node->next = current->next;
			current->next = new_node;
			return (new_node);
		}
		else
			current = current->next;
	}

	return (NULL);
}

