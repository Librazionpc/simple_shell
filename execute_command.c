#include "main.h"

/**
 * perform_args - Takes path from args_exist_in_path and user args
 *
 * @path_needed: Fetches the exact path from args_exist_in_path
 * @args: Fecthes the args from string_manipulation
 *
 * Return: The exit_status
 */
int perform_args(char *path_needed, char **args, char *evnp[])
{
	pid_t child_pid;
	int execve_status = -1;
	int exit_status = 0, status;
	char full_path[15];

	if (path_needed != NULL)
	{
		child_pid = fork();
		if (child_pid < 0)
		{
			return (execve_status);
		}
		if (child_pid == 0)
		{
			if (((strlen(path_needed) > 30) && (strncmp(path_needed, "/", 1) == 0))
					|| (strlen(path_needed) < 3))

			{
				snprintf(full_path, sizeof(full_path), "/bin/%s", args[0]);
				execve_status = execve(full_path, args, evnp);
			}
			else
				execve_status = execve(path_needed, args, evnp);

			if (execve_status < 0)
			{
				free_2d_arrays(args);
				free(path_needed);
				return (exit_status);
			}
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status))
				exit_status = WEXITSTATUS(status);
		}
	}
	free(path_needed);
	free_2d_arrays(args);
	return (exit_status);
}
