#include "lists.h"

/**
 * add_nodeint_end - Function that create a node at the end of a linked list
 * @head: The pointer that pointer to the NULL pointer
 * @n: The interger for the struct
 *
 * Return: The linked list
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *save, *newNode;

	save = *head;
	newNode = malloc(sizeof(listint_t));
	if (newNode == NULL)
		return (NULL);

	newNode->n = n;
	newNode->next = NULL;

	if (*head == NULL)
		*head = newNode;
	else
	{
		while (save->next != NULL)
		{
			save = save->next;
		}
		save->next = newNode;
	}
	return ((*head));
}
