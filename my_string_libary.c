#include "main.h"

void removeLeadingSpaces(char *str)
{
        int len = strlen(str);
        int i, j = 0;
        int foundNonSpace = 0;

        for (i = 0; i < len; i++)
        {
                if (str[i] != ' ')
                        foundNonSpace = 1;
                if (foundNonSpace) 
                        str[j++] = str[i];
        }
        str[j] = '\0';
}

/**
 * string_manipulation - Function that deals user input
 * formating the string command and argument
 *
 * @command: User Input from the main function
 *
 * Return: The args i.e args[0]->command args[1++]->arguments
 */

char **string_manipulation(char *command)
{
	char **args = NULL;
	char *token = NULL;
	char *command_copy = NULL;
	size_t no_tokens = 0;
	int i = 0, j;

	if (command == NULL)
	{
		return (NULL);
	}
	removeLeadingSpaces(command);
	command_copy = strdup(command);
	if (command_copy == NULL)
	{
		free(command);
		return (NULL);
	}
	token = strtok(command_copy, " ");
	if (token == NULL)
	{
		free(command);
		free(command_copy);
		return (NULL);
	}
	while (token != NULL)
	{
		no_tokens++;
		token = strtok(NULL, " ");
	}
	args = (char **)malloc((no_tokens + 1) * sizeof(char *));
	if (args == NULL)
	{
		free(command);
		free(command_copy);
		return (NULL);
	}
	token = strtok(command, " ");
	while (token != NULL)
	{
		args[i] = strdup(token);
		if (args[i] == NULL)
		{
			for (j = 0; j < i; j++)
			{
				free(args[j]);
			}
			free(args);
			free(command);
			free(command_copy);
			return (NULL);
		}
		i++;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
	free(command);
	free(command_copy);
	return (args);
}



int _atoi(char *args)
{
	int number = 0, i = 0, is_negative = 0;

	if (args[i] == '-')
	{
		is_negative = 1;
		i++;
	}

	while (args[i] != '\0')
	{
		number = number * 10 + (args[i] - '0');
		i++;
	}

	if (is_negative)
		number *= -1;
	return (number);
}
