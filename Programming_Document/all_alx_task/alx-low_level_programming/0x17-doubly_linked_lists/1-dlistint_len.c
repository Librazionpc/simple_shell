#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * dlistint_len - Function that returns number of elements in a dlinked lists
 * @h: pointer to the fisrt nod in the list
 *
 * Return: The lenght of the dlinked list
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t i = 0;

	while (h != NULL)
	{
		i++;
		h = h->next;
	}

	return (i);
}
