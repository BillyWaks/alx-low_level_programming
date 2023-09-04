#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: textfile being read
 * @letters: number of letters being read
 *
 * Return: actual number of letters read and print
 * 0: file cannot be opened or read or write/ NULL
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t fd; /*file descriptor that will be used to acccess filename*/
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
