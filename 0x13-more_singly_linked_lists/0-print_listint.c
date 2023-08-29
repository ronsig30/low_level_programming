#include "lists.h"

/**
 * print_listint - displays elements stored in a linked list
 * @h: pointer to the start of the linked list (listint_t)
 *
 * Return: number of elements in the list
 */
size_t print_listint(const listint_t *h)
{
	size_t count = 0;

	while (h)
	{
		printf("%d\n", h->n);
		count++;
		h = h->next;
	}

	return (count);
}
