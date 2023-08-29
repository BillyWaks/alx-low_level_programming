#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint - function returns the number of elements in a linked list
 * @h: pointer to the head of a linked list
 *
 * Return: the number of elements in the list
 */

size_t print_listint(const listint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		count++;
		h = h->next;
	}
	return (count);
}
