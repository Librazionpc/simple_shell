#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * free_list - Function that frees a linked list
 * @head: Fetches the adress of the linked list
 *
 * Return: Nothing
 */

void free_list(list_t *head)
{
	list_t *temp, *headNode;

	temp = head;
	while (temp != NULL)
	{
		headNode = temp->next;
		free(temp->str);
		free(temp);
		temp = headNode;
	}
}
