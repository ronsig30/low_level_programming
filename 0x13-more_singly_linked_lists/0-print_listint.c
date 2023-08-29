#include "lists.h"

/**
 * print_listint - All digits are printed
 * @h: linked list to be printed
 *
 * Return: Number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t digit = 0;

	while (h)
	{
		printf("%d\n", h->n);
		digit++;
		h = h->next;
	}

	return (digit);
}
