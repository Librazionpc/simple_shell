#include "main.h"

/**
 * prompt - Function that prompt the user
 *
 * Return: The command to be executed
 */

char *prompt(environment *env_cmp, environment *alias,
		int exit_status, int fd)
{
	char *command = NULL;
	size_t len = 0;
	ssize_t bytes_read = 0, bytes_written = 0;

	if (isatty(0) && fd == 0)
		bytes_written = write(STDIN_FILENO, "$", 1);

	if (bytes_written == -1)
	{
		free(command);
		exit(exit_status);
	}
	bytes_read = _getline(&command, &len, fd);
	if (bytes_read <= 0)
	{
		free(command);
		free_list(alias);
		free_list(env_cmp);
		exit(exit_status);
	}

	if (command[bytes_read - 1] == '\n')
		command[bytes_read - 1] = '\0';

	return (command);
}
