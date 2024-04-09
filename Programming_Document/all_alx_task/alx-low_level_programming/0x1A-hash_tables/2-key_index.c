#include "hash_tables.h"

/**
 * key_index - Function that calculate the index needed
 * @key: The key of the value;
 * @size: The array size
 *
 * Return: The index
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash = hash_djb2(key);
	unsigned long int index = hash % size;

	return (index);
}
