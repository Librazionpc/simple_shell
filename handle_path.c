#include "main.h"

/**
 * handle_path - Function that works with getpath to provide PATH value
 *
 * Return: Environment PATH, value
 */
char *handle_path(void);
char *handle_path(void)
{
	char path_buffer[MAX_COMMAND_SIZE];
	char *env_val = NULL, *path = NULL;
	char *path_token = NULL, *path_buffer_ptr = NULL;
	size_t buffer_size;
	int bytes_written = 0;

	env_val = getenv("PATH");
	if (env_val == NULL)
	{
		return (NULL);
	}
	buffer_size = sizeof(path_buffer);
	path = strdup(env_val);
	if (path == NULL)
	{
		perror("strdup");
		return (NULL);
	}
	path_token = strtok(path, ":");
	if (path_token == NULL)
	{
		free(path);
		return (NULL);
	}
	path_buffer_ptr = path_buffer;
	while (path_token != NULL && buffer_size > 1)
	{
		bytes_written = snprintf(path_buffer_ptr, buffer_size, "%s/", path_token);
		if (bytes_written < 0)
		{
			perror("snprintf");
			free(path);
			return (NULL);
		}
		path_buffer_ptr += bytes_written;
		buffer_size -= bytes_written;
		path_token = strtok(NULL, ":");
	}
	free(path);
	return (strdup(path_buffer));
}

/**
 * args_exist_in_path - Function that check if user entry in correct
 *
 * @path_buf: Takes in the return of handle_path
 * @args: Takes in the return of string_manipulation
 * @progName: The of the program that is running
 * @runs: Sum of the parent arrays of argv from main
 *
 * Return: The pathname e.g(/bin/ls)
 */

char *args_exist_in_path(char *path_buf, char **args, char *progName, int runs)
{
	char *path_ptr = path_buf, *path_needed = NULL;
	char *cmd_info = NULL;
	size_t path_needed_size;

	while (*path_ptr != '\0' && (strlen(path_buf) > 20))
	{
		path_needed_size = strlen(path_ptr) + 1 + strlen(args[0]) + 2;
		path_needed = (char *)malloc(path_needed_size);

		if (path_needed == NULL)
		{
			return (NULL);
		}
		snprintf(path_needed, path_needed_size, "/%s/%s", path_ptr, args[0]);
		if (access(path_needed, X_OK) == 0)
		{
			cmd_info = (char *)malloc(sizeof(char) * strlen(path_needed) + 1);
			if (cmd_info == NULL)
			{
				return (NULL);
			}
			strcpy(cmd_info, path_needed);
			free(path_needed);
			break;
		}
		path_ptr = strchr(path_ptr, '/');
		if (path_ptr == NULL)
		{
			break;
		}
		path_ptr++;
		free(path_needed);
	}

	if (cmd_info == NULL)
	{
		if(strncmp(args[0], "./", 2) == 0)
		{
			cmd_info = malloc(sizeof(char) * strlen(args[0]) + 1);
			strcpy(cmd_info, args[0]);
			cmd_info[strlen(args[0]) + 1] = '\0';
			return (cmd_info);
		}
		else if (strlen(path_buf) < 20)
		{
			if (access(path_buf, X_OK) == 0)
			{
				cmd_info = malloc(sizeof(char) * strlen(path_buf));
                        	strcpy(cmd_info, path_buf);
                        	return (cmd_info);
			}
		}
		fprintf(stderr, "%s: %d: %s: not found\n", progName, runs, args[0]);
	}
	return (cmd_info);
}

