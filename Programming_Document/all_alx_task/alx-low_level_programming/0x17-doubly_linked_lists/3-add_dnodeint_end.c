#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint_end - Function tha adds to end of the dlinked list
 * @head: Pointer to the first node
 * @n: The data to be stored
 *
 * Return: The new dlinked list
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *temp, *new_dlist;

	if (head == NULL)
		return (NULL);

	new_dlist = malloc(sizeof(dlistint_t));
	if (new_dlist == NULL)
		return (NULL);

	new_dlist->n = n;
	new_dlist->prev = NULL;
	new_dlist->next = NULL;

	if (*head == NULL)
		*head = new_dlist;
	else
	{
		temp = *head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new_dlist;
		new_dlist->prev = temp;
	}

	return (*head);
}
