#include "main.h"


/**
 * create_file - Function that creates a file.
 *
 * @filename: Fetches the argument filename
 * @text_content: Fetches the text to passed
 *
 * Return: 1 on SUCCESS OR -1 on FAILURE
 */

int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t bytes_written;
	mode_t file_permissions = S_IRUSR | S_IWUSR;

	if (text_content == NULL)
	{
		fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, file_permissions);
		if (fd == -1)
			return (-1);
	}
	else
	{
		fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, file_permissions);
		if (fd == -1)
			return (-1);
		bytes_written = write(fd, text_content, strlen(text_content));
		if (bytes_written == -1)
		{
			close(fd);
			return (-1);
		}

		close(fd);
	}

	return (1);
}
