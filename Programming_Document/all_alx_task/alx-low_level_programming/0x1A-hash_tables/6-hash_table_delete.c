#include "hash_tables.h"

/**
 * hash_table_delete - Function that deletes a hash table
 * @ht: Pointer to the hash table
 *
 * Return: Nothing
 */

void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *temp = NULL, *current = NULL;
	unsigned int i;

	if (ht == NULL)
		return;
	for (i = 0; i < ht->size; i++)
	{
		temp = ht->array[i];
		while (temp != NULL)
		{
			current = temp;
			temp = temp->next;
			free(current->key);
			free(current->value);
			free(current);
		}
		ht->array[i] = NULL;
	}

	free(ht->array);
	free(ht);
}
