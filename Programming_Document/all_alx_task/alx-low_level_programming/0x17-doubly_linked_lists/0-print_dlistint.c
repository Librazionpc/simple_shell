#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_dlistint - Function taht prints dlinked lists
 * @h: Pointer toi the first node
 *
 * Return: The amounts of elements
 */

size_t print_dlistint(const dlistint_t *h)
{
	size_t i = 0;

	if (h == NULL)
		return (0);

	while (h != NULL)
	{
		i++;
		printf("%d\n", h->n);
		h = h->next;
	}
	return (i);
}
