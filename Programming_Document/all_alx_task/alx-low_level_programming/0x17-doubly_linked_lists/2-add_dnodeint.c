#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint - Function that adds node to beggining of a dlinked list
 * @head: Pointer to the first node in the lists
 * @n: The data to be stored
 *
 * Return: The new dlinked list
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_dlist;

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
		new_dlist->next = *head;
		(*head)->prev = new_dlist;
		*head = new_dlist;
	}

	return (*head);
}
