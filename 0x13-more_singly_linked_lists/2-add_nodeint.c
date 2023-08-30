#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

/**
 * add_nodeint - adds a new node at the beginning of a linked list
 * @head: double pointer to the header file
 * @n: declares the integer value
 *
 * Return: the address of the new element, or NULL if it failed
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new = malloc(sizeof(listint_t));

	if (new == NULL)
	{
		return (NULL);
	}

	new->n = n;
	new->next = *head;
	*head = new;

	return (new);
}
