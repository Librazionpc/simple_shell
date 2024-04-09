#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - Function that create a node at the end of the list
 *
 * @head: Fetches the head pointer
 * @str: Fetches the string
 *
 * Return: The list
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *newNode, *current;

	newNode = (list_t *)malloc(sizeof(list_t));
	if (newNode == NULL)
	{
		return (0);
	}

	newNode->str = strdup(str);
	newNode->len = strlen(str);
	newNode->next = NULL;
	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = newNode;
	}

	return ((*head));
}
