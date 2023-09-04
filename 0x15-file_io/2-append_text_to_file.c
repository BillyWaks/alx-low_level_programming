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

