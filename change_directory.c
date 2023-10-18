#include "main.h"

void change_directory(char **args, char *progName, int run)
{
	char *current_pwd = NULL, *new_pwd, *old_pwd, *dir_needed;
	size_t new_pwd_size;

	if ((current_pwd = getcwd(NULL, 0)) == NULL)
	{
		return;
	}

	if (strcmp(args[0], "cd") == 0 && args[1] == NULL)
	{
		if (chdir(getenv("HOME")) == 0)
		{
			dir_needed = get_env("HOME");
			setenv("PWD", dir_needed, 1);
			setenv("OLDPWD", current_pwd, 1);
			free(current_pwd);
			return;
		}
	}
	else if (strcmp(args[0], "cd") == 0 && strcmp(args[1], "-") == 0)
	{
		dir_needed = get_env("OLDPWD");
		old_pwd = getcwd(NULL, 0);
		if (chdir(dir_needed) == 0)
		{
			getcwd(dir_needed, 100);
			setenv("PWD", dir_needed, 1);
			setenv("OLDPWD", old_pwd, 1);
			printf("%s\n", get_env("PWD"));
			free(old_pwd);
			free(current_pwd);
			return;
		}
		else
		{
			printf("%s\n", old_pwd);
			free(old_pwd);
			free(current_pwd);
			return;
		}
	}
	else if (*args[1] != '/')
	{
		new_pwd_size = strlen(current_pwd) + strlen(args[1]) + 2;
		new_pwd = malloc(new_pwd_size);
		if (new_pwd == NULL)
		{
			free(current_pwd);
			return;
		}
		snprintf(new_pwd, new_pwd_size, "%s/%s", current_pwd, args[1]);
		if (chdir(new_pwd) == 0)
		{
			setenv("OLDPWD", current_pwd, 1);
			setenv("PWD", new_pwd, 1);
		}
		else
			fprintf(stderr, "%s: %d: %s: can't cd to %s\n", progName, run, args[0], args[1]);
		free(new_pwd);
	}
	else if (*args[1] == '/')
	{
		if (chdir(args[1]) == 0)
		{
			setenv("OLDPWD", current_pwd, 1);
			setenv("PWD", args[1], 1);
		}
		else
			fprintf(stderr, "%s: %d: %s: can't cd to %s\n", progName, run, args[0], args[1]);
	}	
	free(current_pwd);
}
