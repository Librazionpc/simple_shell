#include "main.h"

/**
 * free_2d_arrays - Function that frees 2d arrays
 *
 * @args: Fetches the 2d array to be freed
 *
 * Return: Nothing
 */

void free_2d_arrays(char **args)
{
        int i;

        for (i = 0; args[i] != NULL; i++)
        {
                free(args[i]);
        }

        free(args);
}

/**
 *
 *
 *
 */

int free_linked_list(ListOfPath *path_needed)
{
	ListOfPath *pathList;
	ListOfPath *current, *temp;

	pathList = path_needed;
	current = pathList;

	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp->directory);
		free(temp);
	}
	return 0;
}
