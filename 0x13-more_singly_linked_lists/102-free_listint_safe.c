#include "lists.h"

/**
 * free_listint_safe - Linked list to be freed
 * @head: Pointer to the first node
 *
 * Return: Number of elements in the freed list.
 */
size_t free_listint_safe(listint_t **head)
{
	size_t node_count = 0;
	int memory_diff;
	listint_t *temp;

	if (!head || !*head)
		return (0);

	while (*head)
	{
		memory_diff = *head - (*head)->next;
		if (memory_diff > 0)
		{
			temp = (*head)->next;
			free(*head);
			*head = temp;
			node_count++;
		}
		else
		{
			free(*head);
			*head = NULL;
			node_count++;
			break;
		}
	}

	*head = NULL;

	return (node_count);
}
