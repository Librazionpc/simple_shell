#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - Function that add node to the beggining of linked list
 *
 * @head: Fetches the head pointer
 * @str: Fetches the string
 *
 * Return: The list
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *newNode;

	newNode = (list_t *)malloc(sizeof(list_t));
	if (newNode == NULL)
	{
		return (0);
	}

	newNode->str = strdup(str);
	newNode->len = strlen(str);
	newNode->next = *head;

	*head = newNode;
	return ((*head));
}
