#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * free_dlistint - Function that frees a dlinked list
 * @head: Pointer to the first node in the dlinked list
 *
 * Return: Nothing
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	if (head != NULL)
	{
		while (head != NULL)
		{
			temp = head->next;
			free(head);
			head = NULL;
			head = temp;
		}
	}
}
