#include "main.h"

/**
 * append_text_to_file - a function that appends text at the end of a file
 * @filename: a pointer to the name of the file being created
 * @text_content: contents to be written to the file,
 * returns -1 if filename is NULL
 *
 * Return: 1 on success, -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (len > 0)
	{
		ssize_t bytes_written = write(fd, text_content, len);

		close(fd);

		if (bytes_written != len)
			return (-1);
	}
	else
	{
		close(fd);
	}
	return (1);
}


