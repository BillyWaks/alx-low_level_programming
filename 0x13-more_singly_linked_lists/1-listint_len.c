#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

/**
 * listint_len - function that returns the number of elements in a linked list
 * @h: pointer to the head of a linked list
 *
 * Return: the number of elements in a linked list
 */

size_t listint_len(const listint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}
	return (count);
}
