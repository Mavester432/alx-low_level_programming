#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to POSIX stdout
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters it could read and print
 * if an error occurs, return 0
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t bytes_read, bytes_written;
	char *buffer;

	if (filename == NULL)
	return (0);

	buffer = malloc(letters);
	if (buffer == NULL)

	{
	return (0);
	}

	bytes_read = read(open(filename, O_RDONLY), buffer, letters);
	if (bytes_read == -1)

	{
	free(buffer);
return (0);

	}
	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
	if (bytes_written == -1 || bytes_written != bytes_read)

	{
	free(buffer);
return (0);
	}

	free(buffer);
	return (bytes_written);
}
