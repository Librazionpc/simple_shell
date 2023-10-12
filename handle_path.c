#include "main.h"
#include <stdlib.h>

char *get_path(char *command);
char *concat_string(char *first, char *second);

/**
 * get_full_path - compute the full path of a command
 * @command: the command to compute it full path
 *
 * Return: the full path
 */

char *get_full_path(char *command)
{
	struct stat file_stats;
	char *full_path, *command_cpy = NULL;

	if (command == NULL)
		return (NULL);
	command_cpy = strdup(command);
	if (stat(command, &file_stats) == -1)
	{
		full_path = get_path(command_cpy);
		if (full_path == NULL)
		{
			free(command_cpy);
			return (NULL);
		}
		else
		{
			free(command_cpy);
			return (full_path);
		}
	}
	return (command_cpy);
}

/**
 * get_path - search for each path in the environment variable
 * @command: a command to search for
 *
 * Return: the path if found otherwise return NULL
 */
char *get_path(char *command)
{
	int i = 0;
	struct stat file_stats;
	char **path;
	char *full_path;
	char *result = getenv("PATH");

	if (command == NULL)
		return (NULL);
	if (result == NULL || *result == '\0')
		return (NULL);
	path = split_to_string(result, ':');
	while (path[i] != NULL)
	{
		full_path = concat_string(path[i], command);
		if (stat(full_path, &file_stats) == 0)
		{
			free_2d_arrays(path);
			return (full_path);
		}
		if (full_path != NULL)
		{
			free(full_path);
			full_path = NULL;
		}
		i++;
	}
	free_2d_arrays(path);
	return (NULL);
}

/**
 * concat_string - concatinate two  strigns
 * @first: first string
 * @second: second string
 *
 * Return: the concatinated string
 */
char *concat_string(char *first, char *second)
{
	int len_first = 0;
	int len_second = 0;
	int i = 0, l = 0;
	char *concated_string;

	if (first == NULL || second == NULL)
		return (NULL);

	len_first = strlen(first);
	len_second = strlen(second);

	concated_string = malloc(sizeof(char) * (len_first + len_second + 2));
	if (concated_string == NULL)
		return (NULL);
	for (l = 0; l < len_first; l++)
	{
		concated_string[i] = first[l];
		i++;
	}
	concated_string[i] = '/';
	i++;
	for (l = 0; l < len_second; l++)
	{
		concated_string[i] = second[l];
		i++;
	}
	concated_string[i] = '\0';
	return (concated_string);

}

