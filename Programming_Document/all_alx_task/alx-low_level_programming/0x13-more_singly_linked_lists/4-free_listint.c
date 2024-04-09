#include "lists.h"

/**
 * free_listint - Function that frees the memory
 * @head: pointer to the linked list
 *
 * Returns: Nothing
 */

void free_listint(listint_t *head)
{
	listint_t *save, *clear;

	save = head;
	while (save != NULL)
	{
		clear = save->next;
		free(save);
		save = clear;
	}
}
