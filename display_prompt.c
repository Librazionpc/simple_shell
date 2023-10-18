#include "main.h"

/**
 * prompt - Function that prompt the user
 *
 * Return: The command to be executed
 */

char *prompt(environment *env_cmp, environment *alias)
{
	char *command = NULL;
	size_t len = 0;
	ssize_t bytes_read, bytes_written;

	if (isatty(0))
		bytes_written = write(STDIN_FILENO, "$", 1);
	if (bytes_written == -1)
	{
		free(command);
		exit(EXIT_SUCCESS);
	}
	bytes_read = getline(&command, &len, stdin);
	if (bytes_read <= 0)
	{
		free(command);
		printf("testing\n");
		free_list(alias);
		free_list(env_cmp);
		exit(EXIT_SUCCESS);
	}

	if (command[bytes_read - 1] == '\n')
		command[bytes_read - 1] = '\0';

	return (command);
}
