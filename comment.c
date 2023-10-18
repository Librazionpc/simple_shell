#include "main.h"

/**
 * handle_comment - remove comment in command
 * @command: a pointer to the command
 *
 * Return: nothing
 */
void handle_comment(char *command)
{
	int i  = 0;

	while (command[i] != '\0')
	{
		if (command[0] == '#' ||
				(command[i] == ' ' && command[i + 1] == '#'))
		{
			command[i] = '\0';
			break;
		}
		i++;
	}
}
