#include "main.h"

/**
 * main - Calls the prompt function and pass the it return to shell_processor
 * @argv: The Argument passed form terminal
 * @argc: The Sum of parent arrays of argv from terminal
 *
 * Return: Always 0
 */
int main(int argc, char *argv[], char *evnp[])
{
	char *cmd = NULL;
	int program_runs = 0, exit_status = 0;

	while (1)
	{
		if (argc == 1)
		{
			cmd = prompt(exit_status);
		}
		program_runs++;
		if (isatty(0) == 0)
		{
			if (cmd == NULL)
			{
				exit(exit_status);
			}
		}
		exit_status = shell_processor(cmd, argv[0], program_runs, evnp, exit_status);
	}
	return (exit_status);
}

