#include "lists.h"

/**
 * pop_listint - Function that delete the head of a lionked list
 * @head: Fetches the struct
 *
 * Return: The value that head is points to.
 */

int pop_listint(listint_t **head)
{
	listint_t *save;
	int value;


	if (*head == NULL)
		return (0);
	save = *head;

	value = save->n;
	save = save->next;
	free(*head);
	*head = NULL;
	*head = save;
	return (value);
}
