#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - Function that delete a indexed node
 * @head: The head pointer of the node
 * @index: The index needed
 *
 * Return: 1 on Success
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp, *save;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	temp = *head;
	if (index == 0)
	{
		*head = temp->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(temp);
		return (1);
	}
	while (temp != NULL && i < index)
	{
		i++;
		save = temp;
		temp = temp->next;
	}

	if (temp == NULL)
		return (-1);
	save->next = temp->next;

	if (temp->next != NULL)
		temp->next->prev = save;

	free(temp);
	temp = NULL;

	return (1);
}
