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
int shell_processor(char *command, char *progName, int no_runs, char *envp[], int exit_status)
{
	char **args = NULL;
	char *path_needed = NULL;

	args = string_manipulation(command);
	if (args == NULL)
	{
		return (exit_status);
	}
	if (strcmp(args[0], "env") == 0)
	{
		exit_status = print_hsh_envp();
		free_2d_arrays(args);
		return (exit_status);
	}
	path_needed = menu(args, progName, no_runs, exit_status);
	if (path_needed == NULL)
	{
		free_2d_arrays(args);
		exit_status = 127;
		return (exit_status);
	}
	exit_status = perform_args(path_needed, args, envp);

	return (exit_status);
}
