#include "main.h"

/**
 * string_manipulation - Function that deals user input
 * formating the string command and argument
 *
 * @command: User Input from the main function
 *
 * Return: The args i.e args[0]->command args[1++]->arguments
 */
char **string_manipulation(char *command);
char **string_manipulation(char *command)
{
	int args_count = 0, i;
	char *token = NULL;
	char **args = NULL;
	char *cmd = NULL;
	char *command_copy = NULL;

	command_copy = strdup(command);
	if (command_copy == NULL)
	{
		return (NULL);
	}
	cmd = command_copy + strlen(command_copy);
	while (cmd > command_copy && *(cmd - 1) != '/')
	{
		cmd--;
	}
	if (*cmd == '/')
	{
		cmd++;
	}
	args = (char **)malloc(MAX_ARGS_SIZE * sizeof(char *));
	if (args == NULL)
	{
		free(command_copy);
		return (NULL);
	}

	token = strtok(cmd, " ");
	if (token == NULL)
	{
		free(command_copy);
		args[0] = NULL;
		return(args);
	}

	while (token != NULL && args_count < MAX_ARGS_SIZE)
	{
		args[args_count] = strdup(token);
		if (args[args_count] == NULL)
		{
			free(command_copy);
			for (i = 0; i < args_count; i++)
			{
				free(args[i]);
			}
			free(args);
			return (NULL);
		}
		token = strtok(NULL, " ");
		args_count++;
	}

	args[args_count] = NULL;
	free(command);
	free(command_copy);
	return (args);
}

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
