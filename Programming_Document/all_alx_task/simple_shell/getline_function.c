#include "main.h"

/**
 * _getline - imitate the getline function
 * @lineptr: a pointer to the buffer to save the line read
 * @n: the size of the buffer
 * Return: the number of byte read
 */
ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	char *line = NULL, *temp = NULL;
	size_t len = 0;
	ssize_t bytes_read;
	size_t buffer_bytes = 128;

	if (lineptr == NULL || n == NULL)
		return (-1);
	if (*lineptr == NULL)
	{
		*n = buffer_bytes;
		line = (char *)malloc(*n);
		if (line == NULL)
			return (-1);
		*lineptr = line;
	}
	line = *lineptr;
	while ((bytes_read = read(fd, line + len, 1)) > 0)
	{
		len += bytes_read;
		if (line[len - 1] == '\n')
		{
			break;
		}
		if (len + 1 >= *n)
		{
			*n *= 2;
			temp = realloc(line, *n);
			if (temp == NULL)
			{
				free(line);
				return (-1);
			}
			line = temp;
			*lineptr = line;
		}
	}
	if (bytes_read == -1)
	{
		free(line);
		return (-1);
	}
	return (len);
}

