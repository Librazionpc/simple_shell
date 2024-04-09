#include "hash_tables.h"

/**
 * hash_table_get - Function that retrieves the value associated with a key
 * @ht: Pointer to the table
 * @key: The key for the value needed
 *
 * Return: The value on Success
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned int hash_index;
	char *value = NULL;
	hash_node_t *temp = NULL;
	int found = 0;

	if (key == NULL || *key == '\0' || ht == NULL)
		return (NULL);

	hash_index = key_index((unsigned char *)key, ht->size);

	temp = ht->array[hash_index];
	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
		{
			found = 1;
			value = temp->value;
			break;
		}
		temp = temp->next;
	}

	if (!found)
		return (NULL);
	else
		return (value);
}
