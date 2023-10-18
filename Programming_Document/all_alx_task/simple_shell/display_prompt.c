#include "main.h"

/**
 * prompt - Function that prompt the user
 *
 * Return: The command to be executed
 */

char *prompt(int exit_status)
{
	char *command = NULL;
	size_t len = 0;
	ssize_t bytes_read, bytes_written = 1;

	if (isatty(0))
		bytes_written = write(STDIN_FILENO, "$", 1);
	if (bytes_written == -1)
		return (NULL);
	bytes_read = getline(&command, &len, stdin);
	if (bytes_read <= 0)
	{
		free(command);
		exit(exit_status);
	}
	if (command[bytes_read - 1] == '\n')
		command[bytes_read - 1] = '\0';
	return (command);
}

