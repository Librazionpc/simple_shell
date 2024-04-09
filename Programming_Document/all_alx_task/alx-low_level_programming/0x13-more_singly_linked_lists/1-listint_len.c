#include "lists.h"

/**
 * listint_len - Function that returns the lenght of a linked list
 * @h: The NULL pointer
 *
 * Return: The lenght of the list
 */

size_t listint_len(const listint_t *h)
{
	int count = 0;
	const listint_t *node;

	if (h == NULL)
		return (0);
	node = h;
	while (node != NULL)
	{
		count++;
		node = node->next;
	}
	return (count);
}
