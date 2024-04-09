#include <stdlib.h>
#include "main.h"

/**
 * _realloc - Function that reallocates a memory block using malloc and free
 *
 * @ptr: Old pointer
 * @old_size: old pointer size
 * @new_size: new_size pointer size
 *
 * Return: Return the new allocated memory
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int a;
	char *ptr_new;
	char *save = (void *)ptr;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		ptr = malloc(new_size);
		return (ptr);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	ptr_new = malloc(new_size);
	if (ptr_new == NULL)
		return (NULL);
	for (a = 0; a < old_size; a++)
		ptr_new[a] = save[a];
	free(ptr);
	return ((void *)ptr_new);
}
