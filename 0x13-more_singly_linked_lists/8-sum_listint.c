#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
#include <strings.h>

/**
 * sum_listint - returns the sum of all the data (n) of a listint_t linked list
 * @head: pointer to the first element in the list
 *
 * Return: 0 when the list is empty
 */

int sum_listint(listint_t *head)
{
	int sum = 0; /*initialization*/
	listint_t *node = head;

	while (node)
	{
		sum += node->n;
		node = node->next;
	}

	return (sum);
}

