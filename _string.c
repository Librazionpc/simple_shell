#include "main.h"

/**
 * string_manipulation - Function that deals user input
 * formating the string command and argument
 *
 * @command: User Input from the main function
 *
 * Return: The args i.e args[0]->command args[1++]->arguments
 */
void removeLeadingSpaces(char *str);
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
		return (NULL);
	if ((*command_copy == '/') || ((strrchr(command, '/') != NULL)
			&& (*command_copy != '.')))
	{
		cmd = command_copy;
		cmd++;
		while (*cmd != '/' && *cmd != '\0')
		{
			cmd++;
		}
		if (*cmd == '/')
		{
			*cmd = '\0';
			cmd++;
		}
		token = strtok(cmd, " ");
	}
	else
		token = strtok(command_copy, " ");
	args = (char **)malloc(MAX_ARGS_SIZE * sizeof(char *));
	if (args == NULL)
	{
		free(command_copy);
		return (NULL);
	}
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

void removeLeadingSpaces(char *str)
{
	int len = strlen(str);
	int i, j = 0;
	int foundNonSpace = 0;

	for (i = 0; i < len; i++)
	{
		if (!(str[i] == ' '))
			foundNonSpace = 1;
		if (foundNonSpace) 
			str[j++] = str[i];
	}
	str[j] = '\0';
}


char *string_manipulation2(char *command)
{
	char *args = NULL;
	char *token = NULL;


	token = strtok(command, " ");
	if (token == NULL)
		return (NULL);
	args = strdup(token);
	if (args == NULL)
	{
		return (NULL);
	}

	free(command);
	return (args);
}
