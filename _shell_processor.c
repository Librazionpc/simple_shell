#include "main.h"

/**
 * shell_processor - Function that recieves the user input
 * and pass it accordingly calling each function at the expected time
 *
 * @command: The user input
 * @progName: The of the program that is running
 * @no_runs: Sum of the parent arrays of argv from main
 *
 * Return: Null to the main funtion to cause continuation
 */

char *shell_processor(char *command, char *progName, int no_runs, char *evnp[])
{
	char **args = NULL;
	char *path_buffer = NULL;
	char *path_needed = NULL;

	args = string_manipulation(command);
	if (args[0] == NULL)
	{
		free_2d_arrays(args);
		return (NULL);
	}

	if (strncmp(args[0], "env", 3) == 0)
		handle_evnp(evnp);
	path_buffer = handle_path();
	if (path_buffer == NULL)
	{
		free_2d_arrays(args);
		free(path_buffer);
		return (NULL);
	}
	path_needed = args_exist_in_path(path_buffer, args, progName, no_runs);
	if (path_needed == NULL)
	{
		free_2d_arrays(args);
		free(path_buffer);
		return (NULL);
	}
	perform_args(path_needed, args, evnp);
	free(path_buffer);
	return (NULL);
}
