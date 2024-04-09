#include "lists.h"

/**
 * list_len - Function that print the how many elements in a list
 *
 * @h: Fetches the list
 *
 * Return: The elements lenght
 */

size_t list_len(const list_t *h)
{
	int count = 0;
	const list_t *temp = h;

	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}
