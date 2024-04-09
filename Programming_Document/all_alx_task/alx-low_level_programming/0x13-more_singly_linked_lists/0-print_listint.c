#include "lists.h"

/**
 * print_listint - Function that print the element of a linked list
 * @h: A NULL pointer
 *
 * Return: the lenght of the string
 */

size_t print_listint(const listint_t *h)
{
	size_t count = 0;
	const listint_t *node;

	if (h == NULL)
		return (0);
	node = h;
	while (node != NULL)
	{
		count++;
		printf("%d\n", node->n);
		node = node->next;
	}
	return (count);
}
