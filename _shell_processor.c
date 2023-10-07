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
int shell_processor(char *command, char *progName, int no_runs, char *evnp[]);
int shell_processor(char *command, char *progName, int no_runs, char *evnp[])
{
	char **args = NULL;
	char *path_buffer = NULL;
	char *path_needed = NULL;
	char *command_copy = NULL;
	char *args2 = NULL;
	int exit_status = 0;
	size_t len = 0;

	command_copy = strdup(command);
	removeLeadingSpaces(command);
	args = string_manipulation(command);
	if (args[0] == NULL)
	{
		free_2d_arrays(args);
		free(command_copy);
		return (exit_status);
	}
	args2 = string_manipulation2(command_copy);
	if (args2 == NULL)
	{
		free_2d_arrays(args);
		free(command_copy);
		return (exit_status);
	}
	if (strncmp(args[0], "env", 3) == 0)
		handle_evnp(evnp);

	path_buffer = handle_path();
	if (path_buffer == NULL || (path_buffer != NULL && strncmp(args[0], ".", 1) == 0))
	{
		free(path_buffer);
		len = strlen(args2) + 1;
		path_buffer = (char *)malloc(sizeof(char) * len);
		strcpy(path_buffer, args2);
		path_buffer[len - 1] = '\0';
	}

	path_needed = args_exist_in_path(path_buffer, args, progName, no_runs);
	if (path_needed == NULL)
	{
		free_2d_arrays(args);
		free(path_buffer);
		exit_status = 127;
		return (exit_status);
	}
	exit_status = perform_args(path_needed, args, evnp);
	free(args2);
	free(path_buffer);
	return (exit_status);
}
