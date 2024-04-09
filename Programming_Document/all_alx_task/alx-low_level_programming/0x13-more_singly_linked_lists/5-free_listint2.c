#include "lists.h"

/**
 * free_listint2 - Function that free a listint_t list
 * @head: The pointer to head of the linked list
 *
 * Return: Nothing
 */

void free_listint2(listint_t **head)
{
	listint_t *save;

	if (head == NULL)
		return;
	save = *head;
	while (save != NULL)
	{
		save = save->next;
		free(*head);
		*head = save;
	}
	head = NULL;
}
