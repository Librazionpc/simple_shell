#include "main.h"

/**
 * prompt - Function that prompt the user
 *
 * Return: The command to be executed
 */

char *prompt(void)
{
	char *command = NULL;
	size_t len = 0;
	ssize_t bytes_read, bytes_written;

	if (isatty(0))
		bytes_written = write(STDIN_FILENO, "$", 1);
	if (bytes_written == -1)
	{
		printf("Nah me %s\n", command);
		free(command);
		return (NULL);
	}
	bytes_read = getline(&command, &len, stdin);
	if (bytes_read <= 0)
	{
		free(command);
		return (NULL);
	}

	if (strncmp(command, "exit", 4) == 0)
	{
		free(command);
		exit(EXIT_SUCCESS);
	}
	if (command[0] == '\n')
	{
		free(command);
		return (NULL);
	}

	if (command[bytes_read - 1] == '\n')
		command[bytes_read - 1] = '\0';

	return (command);
}
