#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * sum_dlistint - Functions of that sums up integer in a dlinked_list
 * @head: The poineter to the fisrt node
 *
 * Return: The Sum of the data
 */

int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	if (head == NULL)
	{
		return (0);
	}

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
