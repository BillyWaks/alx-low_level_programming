#include "main.h"
#include <strings.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

/**
 * main - Entry point into the program
 * @argv: array of command-line arguments
 * @argc: number of command-line arguments
 *
 * Return: 0 on success, 97 for wrong arguments, 98 for read error,
 *         99 for write error, 100 for close error
 */

int main(int argc, char *argv[])
{
	/*initialization*/
	char *file_from = argv[1];
	char *file_to = argv[2];
	int fd_from, fd_to;
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s cp file_from file_to\n", argv[0]);
		return (97);
	}


	/*open the source file for reading*/
	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s/n", file_from);
		return (98);
	}

	/*create the destination file for writing with permissions rw-rw-r--*/
	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to file %s/n", file_to);
		close(fd_from);
		return (99);
	}

	while ((bytes_read = read(fd_from, buffer, sizeof(buffer))) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to file %s/n", file_to);
			return (99);
		}
	}

	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s/n", file_from);
		return (98);
	}

	if (close(fd_from) == -1 || close(fd_to == -1))
	{
		dprintf(STDERR_FILENO, "Error: Can't close file descriptors\n");
		return (100);
	}

	return (0);
}
