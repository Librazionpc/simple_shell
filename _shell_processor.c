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
int shell_processor(char *command, char *progName, int no_runs, char *evnp[], int exit_code)
{
	char **args = NULL;
	char *path_needed = NULL;
	int exit_status = 0;

	args  = split_to_string(command, ' ');
	if (args == NULL)
		return (exit_status);
	if (*args != NULL)
	{
		if (strcmp(args[0], "exit") == 0)
		{
			free_2d_arrays(args);
			free(command);
			exit(exit_code);
		}
		else if (strcmp(args[0], "env") == 0)
			exit_status = print_env(evnp);
		else
		{
			path_needed = get_full_path(args[0]);
			if (path_needed != NULL)
			{
				if (access(path_needed, X_OK) == 0) 
				{
					exit_status = perform_args(path_needed, args, evnp);
					free(path_needed);
					free_2d_arrays(args);
					return (exit_status);
				}
				else 
				{
					perror("Error");
					free(path_needed);
					free_2d_arrays(args);
					return (130);
				}
			}
			_fprintf(STDERR_FILENO, "%s: %d: %s: not found\n", progName, no_runs, command);
			free_2d_arrays(args);
			return (127);
		}
	}
	return (exit_status);
}
