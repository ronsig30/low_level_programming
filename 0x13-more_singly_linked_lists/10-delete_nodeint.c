#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes a node in a linked lists
 * @head: Pointer to a pointer to the first element of the list.
 * @index: Index of the node to delete.
 *
 * Return: 1 (Success) or -1 (Failure).
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *prev_node = *head;
	listint_t *current_node = NULL;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(prev_node);
		return (1);
	}

	while (i < index - 1)
	{
		if (!prev_node || !(prev_node->next))
			return (-1);
		prev_node = prev_node->next;
		i++;
	}

	current_node = prev_node->next;
	prev_node->next = current_node->next;
	free(current_node);

	return (1);
}
