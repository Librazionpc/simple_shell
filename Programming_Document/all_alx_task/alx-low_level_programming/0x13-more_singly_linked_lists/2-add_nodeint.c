#include "lists.h"

/**
 * add_nodeint - Function that a node to the beggining of a linked list
 * @head: Pointer to The NULL head pointer
 * @n: The interger in the struct
 *
 * Return: The linked list
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *save;
	listint_t *newNode;

	save = *head;
	newNode = malloc(sizeof(listint_t));
	if (newNode == NULL)
		return (NULL);
	(*newNode).n = n;
	if (head == NULL)
		*head = newNode;
	else
	{
		newNode->next = save;
		*head = newNode;
	}
	return (*head);
}
