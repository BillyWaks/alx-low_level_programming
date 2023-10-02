#include "main.h"

/**
 * read_textfile - a function that reads a text file and prints it
 * @filename: textfile being read
 * @letters: number of letters being read
 *
 * Return: 0 if filename is NULL, the file cannot be opened or read/write
 *          actual number of the letters
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t fd; /*used to acccess filename*/
	char *buffer; /*declares a pointer used to store the read data*/
	ssize_t w; /*stores the return value for write function*/
	ssize_t t; /*stores the return value for read function*/

	fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	t = read(fd, buffer, letters);
	w = write(STDOUT_FILENO, buffer, t);

	free(buffer);
	close(fd);
	return (w);
}
