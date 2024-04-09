#include "main.h"

/**
 * read_textfile - Function that reads a text file
 * @filename: Fetches the argument filename
 * @letters: Amount of string to be read
 *
 * Return: the bytes_read
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *input_buffer;
	ssize_t bytes_read = 0, bytes_written;
	size_t len = 0;
	int fd;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);

	input_buffer = malloc(letters + 1);
	if (input_buffer == NULL)
	{
		close(fd);
		return (0);
	}
	bytes_read = read(fd, input_buffer, letters);
	if (bytes_read < 0)
	{
		free(input_buffer);
		close(fd);
		return (0);
	}
	len += bytes_read;
	input_buffer[bytes_read] = '\0';
	bytes_written = write(STDOUT_FILENO, input_buffer, bytes_read);
	if (bytes_written < 0)
	{
		free(input_buffer);
		close(fd);
		return (0);
	}
	free(input_buffer);
	close(fd);
	return (len);
}
