#include "main.h"

/**
 *
 *
 *
 *
 */

char *menu(char **args, char *progName, int run, int exit_status)
{
	char *cmd_info = NULL;
	ListOfPath *path_buffer = NULL;

	if (strcmp(args[0], "exit") == 0)
        {
		free_2d_arrays(args);
		exit(exit_status);
        }
        else if (access(args[0], F_OK) == 0 && access(args[0], X_OK) == 0)
	{
		cmd_info = strdup(args[0]);
	}
	else if (strcmp(args[0], "cd") == 0)
	{
		change_directory(args, progName, run);
		return (NULL);
	}
	else if (strcmp(args[0], "setenv") == 0)
	{
		_setenv(args[1], args[2], 1);
		return (NULL);
	}
	else
	{
		path_buffer = createLinkedListOfPath();
		cmd_info = args_exist_in_path(path_buffer, args);
		free_linked_list(path_buffer);
	}
	if (cmd_info == NULL)
        {
                fprintf(stderr, "%s: %d: %s: not found\n", progName, run, args[0]);
        }
	return (cmd_info);
}
