#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * add_directory_to_list - Function that add the directory to the
 * linked list
 * head: The pointer to the first node
 * directory: The directory to be added
 *
 * Return: Nothing
 */
void add_directory_to_list(ListOfPath **head, const char *directory)
{
	ListOfPath *newNode = NULL;
	ListOfPath *current = NULL;

	newNode = (ListOfPath *)malloc(sizeof(ListOfPath));
	if (newNode == NULL)
	{
		perror("malloc");
		return;
	}
	current = *head;
	newNode->directory = strdup(directory);
	if (newNode->directory == NULL)
	{
		free(newNode);
		return;
	}
	newNode->next = NULL;

	if (*head == NULL)
		*head = newNode;
	else
	{
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = newNode;
	}
}

/**
 * createLinkedListofPath - Function that creates a linked for the path
 *
 * Return: The list
 */

ListOfPath *createLinkedListOfPath()
{
	char *env_val = NULL, *path = NULL;
	char *path_token = NULL;
	ListOfPath *head = NULL;

	env_val = get_env("PATH");
	if (env_val == NULL)
	{
		return (NULL);
	}
	path = strdup(env_val);
	if (path == NULL)
	{
		perror("strdup");
		return (NULL);
	}
	path_token = strtok(path, ":");

	if (path_token == NULL)
	{
		free(path);
		return (NULL);
	}

	while (path_token != NULL)
	{
		add_directory_to_list(&head, path_token);
		path_token = strtok(NULL, ":");
	}
	
	free(path);
	return (head);
}
char *args_exist_in_path(ListOfPath *path_list, char **args)
{
	char *cmd_info = NULL, *path_needed = NULL;
	size_t path_needed_size;

	while (path_list != NULL)
	{
		path_needed_size = strlen(path_list->directory) + strlen(args[0]) + 2;

		path_needed = (char *)malloc(path_needed_size);
		if (path_needed == NULL)
		{
			perror("malloc");
			return (NULL);
		}

		snprintf(path_needed, path_needed_size, "%s/%s", path_list->directory, args[0]);
		if (access(path_needed, F_OK | X_OK) == 0)
		{
			cmd_info = strdup(path_needed);
			free(path_needed);
			return (cmd_info);
		}

		free(path_needed);
		path_list = path_list->next;
	}
	return (cmd_info);
}
