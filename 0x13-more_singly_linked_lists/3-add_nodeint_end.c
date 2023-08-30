#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

/**
 * add_nodeint_end - adds a new node at the end of a linked list
 * @head: double pointer to the header file
 * @n: declares the integer value
 *
 * Return: the address of the new element, or NULL if it failed
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node;

	listint_t *current = *head;

	/*Create a new node*/
	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	/*inialization of a new node*/
	new_node->n = n;
	new_node->next = NULL;

	/*point the last node to first node*/
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	while (current->next)
		current = current->next;

	current->next = new_node;

	return (new_node);
}

