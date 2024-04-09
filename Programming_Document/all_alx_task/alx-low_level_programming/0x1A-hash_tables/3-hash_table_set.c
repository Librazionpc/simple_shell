#include "hash_tables.h"

/**
 * hash_table_set - Function that adds an element to the hash table
 * @key: The key for the value
 * @value: The content it self
 *
 * Return: 1 on Success and 0 on Failure
 *
 */
hash_node_t *create_new_node(const char *key, const char *value);
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned int hash_index;
	hash_node_t *node = NULL;

	if (key == NULL || *key == '\0' || ht == NULL)
		return (0);

	if (value == NULL)
		return (0);

	node = create_new_node(key, value);
	if (node == NULL)
		return (0);
	hash_index = key_index((unsigned char *)key, ht->size);
	if (ht->array[hash_index] != NULL)
	{
		node->next = ht->array[hash_index];
	}
	ht->array[hash_index] = node;
	return (1);
}


/**
 * create_new_node - Function that the nodes to be add to
 * the array or hash table
 *
 * @key: The key for the value
 * @value: The ccontent itself
 *
 * Return: The newly created node
 */

hash_node_t *create_new_node(const char *key, const char *value)
{
	hash_node_t *new_node = NULL;

	new_node = (hash_node_t *)malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (NULL);

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->next = NULL;

	return (new_node);
}
