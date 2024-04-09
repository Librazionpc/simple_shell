#include <stdio.h>
#include "lists.h"

/**
 * print_list - Funtion that print from a linked list
 *
 * @h: Fetches the linked list
 *
 * Return: the size of the list
 */

size_t print_list(const list_t *h)
{
	const list_t *temp = h;
	size_t count = 0;

	if (h == NULL)
		return (0);
	while (temp != NULL)
	{
		if (temp->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%d] %s\n", temp->len, temp->str);
		count++;
		temp = temp->next;

	}
	return (count);
}
