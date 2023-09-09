#include "main.h"
#include <strings.h>
#include <stdio.h>

/**
 * handle_error - Print an error message and exit with the given exit code.
 * @msg: The error message to print.
 * @exit_code: The exit code to use when exiting.
 */
void handle_error(const char *msg, int exit_code)
{
	perror(msg);
	exit(exit_code);
}

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
	int from, to;
	char *buffer = malloc(BUFSIZ);
	ssize_t bytes_read, bytes_written;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		return (97);
	}

	from = open(argv[1], O_RDONLY);

	if (from == -1)
	{
		handle_error("Error: Can't open source file", 98);
	}

	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	if (to == -1)
	{
		handle_error("Error: Can't create or write to destination file", 99);
	}

	if (buffer == NULL)
	{
		handle_error("Error: Memory allocation failed", 99);
	}

	while ((bytes_read = read(from, buffer, BUFSIZ)) > 0)
	{
		bytes_written = write(to, buffer, bytes_read);
		if (bytes_written != bytes_read)
		{
			handle_error("Error: Write error to destination file", 99);
		}
	}

	if (bytes_read == -1)
	{
		handle_error("Error: Read error from source file", 98);
	}

	free(buffer);
	close(from);
	close(to);

	return (0);
}
