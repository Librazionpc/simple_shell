#include "main.h"

/**
 * fileio - Function hanlde file and user input from stdin
 * @argv: The args passed on command line with the progam;
 * @fd: file decriptor
 * @argc: no of args from command line
 * @exit_status: The exit code
 * @program_runs: The how many time main called prompt
 *
 * Return: The command needed
 */
char *fileio(char **argv, int *fd, int argc, int exit_status, int program_runs)
{
	char *cmd = NULL;

	if (argc == 1)
	{
		cmd = prompt(exit_status, 0);
	}
	else
	{
		if (access(argv[1], F_OK) == 0)
		{
			if (program_runs == 0)
				*fd = open(argv[1], O_RDONLY);
			cmd = prompt(exit_status, *fd);
		}
		else
		{
			fprintf(stderr, "%s: %d: cannot open %s: No such file\n",
					argv[0], program_runs, argv[1]);
			exit(2);
		}
	}
	return (cmd);
}
