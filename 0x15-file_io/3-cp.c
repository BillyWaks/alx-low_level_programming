#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void close_file(int fd);
char *create_buffer(void);

/**
 * close_file - Closes a file descriptor.
 * @fd: The file descriptor to be closed.
 *
 * Return: Nothing.
 */
void close_file(int fd)
{
	int ret;

	ret = close(fd);
	if (ret == -1)
	{
		perror("Error");
		exit(100);
	}
}

/**
 * create_buffer - Allocates a buffer of 1024 bytes.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(void)
{
	char *buffer;

	buffer = malloc(1024);
	if (buffer == NULL)
	{
		perror("Error");
		exit(99);
	}
	return (buffer);
}

/**
 * main - Entry point of the program.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success, or an exit code on failure.
 */
int main(int argc, char *argv[])
{
	int from, to, rd, wr;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer();
	from = open(argv[1], O_RDONLY);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	if (from == -1 || to == -1)
	{
		perror("Error");
		free(buffer);
		exit(98);
	}

	do {
		rd = read(from, buffer, 1024);
		if (rd == -1)
		{
			perror("Error");
			free(buffer);
			close_file(from);
			close_file(to);
			exit(98);
		}

		wr = write(to, buffer, rd);
		if (wr == -1 || wr != rd)
		{
			perror("Error");
			free(buffer);
			close_file(from);
			close_file(to);
			exit(99);
		}
	} while (rd > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}

