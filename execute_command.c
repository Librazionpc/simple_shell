#include "main.h"

/**
 * perform_args - Takes path from args_exist_in_path and user args
 *
 * @path_needed: Fetches the exact path from args_exist_in_path
 * @args: Fecthes the args from string_manipulation
 *
 * Return: The exit_status
 */
int perform_args(char *path_needed, char **args)
{
	pid_t child_pid;
	int execve_status = -1;
	int exit_status = -1, status;
	char **envp = {NULL};


	if (path_needed != NULL)
	{
		child_pid = fork();
		if (child_pid < 0)
		{
			return (execve_status);
		}
		if (child_pid == 0)
		{
			execve_status = execve(path_needed, args, envp);
			if (execve_status < 0)
			{
				free_2d_arrays(args);
				free(path_needed);
				return (execve_status);
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
