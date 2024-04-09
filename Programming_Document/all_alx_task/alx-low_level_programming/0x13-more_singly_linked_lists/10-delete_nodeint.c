#include "lists.h"

/**
 * delete_nodeint_at_index - Funtion that delete indexed node
 * @head: The linked list
 * @index: node to be deleted
 *
 * Return: 1 on sucess
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *save, *current;
	unsigned int i;

	if (head == NULL)
		return (-1);

	save = *head;

	if (index == 0)
	{
		*head = save->next;
		free(save);
		return (1);
	}

	for (i = 0; i < index && save != NULL; i++)
	{
		if (save->next == NULL)
			return (-1);
		save = save->next;
	}
	current= save->next;
	save->next = current->next;
	free(current);
	return (1);
}
