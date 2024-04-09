#include "lists.h"

/**
 * sum_listint - Function that calculate the sum of integer of the element
 * @head: The struct to be dealt with
 *
 * Return: The sum
 */

int sum_listint(listint_t *head)
{
	listint_t *save;
	int sum = 0;

	if (head == NULL)
		return (0);
	save = head;
	while (save != NULL)
	{
		sum += save->n;
		save = save->next;
	}
	return (sum);
}
