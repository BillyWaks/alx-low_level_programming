#include <stdio.h>
#include <lists.h>

/**
 * print_list - prints the details of the linked list
 * @h: pointer to the head of the linked list
 *
 * Return: the number of nodes
 */

size_t print_list(const list_t *h);
{
	size_t count = 0;

	while (h != NULL)
	{
		printf("[%lu]", h->len);
			if (h->str == NULL)
				printf("(nil)/n");
			else
				printf("%s/n", h->str);

			h = h->next;
			count++;
	}
	return (count);
}
