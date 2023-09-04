#include "main.h"

/**
 * create_file - a function that creates a file
 * @filename: name of the file to be created
 * @text_content: contents of the file, if NULL, return -1
 *
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int new_file, len, wr;

	if (filename == NULL)
		return (-1);
	new_file = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (new_file == -1)
		return (-1);

	if (text_content != NULL)
	{

		for (len = 0; text_content[len];)
			len++;
	}

		wr = write(new_file, text_content, len);

		if (wr == -1)
		{
			close(new_file);
			return (-1);
		}
	close(new_file);
	return (1);
}
