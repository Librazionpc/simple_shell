#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_dnodeint_at_index - Insert a nonde at particlar index
 * @h: The head pointer of the node
 * @idx: The node to inserted
 * @n: The data to be placed
 * Return: The newly added node amongst the old ones
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *temp, *new_dlist, *state, *save;
	unsigned int i = 0;
	size_t len = 0;

	if (h == NULL)
		return (NULL);
	temp = *h;
	len = dlistint_len(temp);
	while (temp != NULL && i < idx)
	{
		i++;
		save = temp;
		temp = temp->next;
	}
	if (i == 0)
	{
		state = add_dnodeint(h, n);
		return (state);
	}
	else if (i == (idx - 1) && temp != NULL)
	{
		state = add_dnodeint_end(h, n);
		return (state);
	}
	else if (idx < len)
	{
		new_dlist = malloc(sizeof(dlistint_t));
		if (new_dlist == NULL)
			return (NULL);
		new_dlist->n = n;
		new_dlist->prev = save;
		new_dlist->next = temp;
		if (save != NULL)
			save->next = new_dlist;
		if (temp != NULL)
			temp->prev = new_dlist;
		return (new_dlist);
	}
	return (NULL);
}

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
