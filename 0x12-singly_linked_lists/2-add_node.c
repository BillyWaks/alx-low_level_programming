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
	/*initialization*/
	list_t *new_node;
	unsigned int l = 0;

	while (str[l])
		l++;

	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
	new_node->l = l;
	new_node->next = (*head);
	(*head) = new_node;

	return (*head);
}

