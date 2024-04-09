#include "main.h"

/**
 * cp - Funtion that copies content from file1 to file2
 * @file1: Fetches the main file
 * @file2: Fetches the file to be copied to
 *
 * Return: Nothing
 */
void cp(const char *file1, const char *file2);
void cp(const char *file1, const char *file2)
{
	int fd1, fd2, errno_close1, errno_close2;
	char buffer[1024];
	ssize_t bytes_read, bytes_written;

	fd1 = open(file1, O_RDONLY);
	if (fd1 < 0)
	{
		dprintf(2, "Error: Can't read from file %s\n", file1);
		exit(98);
	}
	fd2 = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd2 < 0)
	{
		dprintf(2, "Error: Can't write to %s\n", file2);
		exit(99);
	}
	while ((bytes_read = read(fd1, buffer, 1024)) > 0)
	{
		if (bytes_read == -1)
		{
			dprintf(2, "Error: Can't read from file %s\n", file1);
			close(fd1);
			close(fd2);
			exit(98);
		}
		bytes_written = write(fd2, buffer, bytes_read);
		if (bytes_written == -1)
		{
			dprintf(2, "Error: Can't write to %s\n", file2);
			close(fd1);
			close(fd2);
			exit(99);
		}
	}
	errno_close1 = close(fd1);
	if (errno_close1 == -1)
	{
		dprintf(2, "Error: Can't close %d", errno_close1);
		exit(100);
	}
	errno_close2 = close(fd2);
	if (errno_close2 == -1)
	{
		dprintf(2, "Error: Can't close %d", errno_close2);
		exit(100);
	}
}


/**
 * main - Funtion that pass the args to my cp function
 * @argc: The number of args passed
 * @argv: The args passed "string"
 *
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 3)
		dprintf(2, "Usage: cp file_from file_to\n");
	else
		cp(argv[1], argv[2]);
	return (0);
}
