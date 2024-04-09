#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * get_dnodeint_at_index - Function that uses index to
 * fetches data from a dlinked list
 *
 * @head: Pointer to the first node
 * @index: The position of the data to be fetched
 *
 * Return: The data that was indexed
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0;

	while (head != NULL && i < index)
	{
		head = head->next;
		i++;
	}
	if (head == NULL)
		return (NULL);
	return (head);
}
