#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *allocate_buffer(char *output_file);
void close_descriptor(int descriptor);

/**
 * allocate_buffer - Allocates 1024 bytes for a buffer.
 * @output_file: The name of the file where data will be written.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *allocate_buffer(char *output_file)
{
	char *output_buffer;

	output_buffer = malloc(sizeof(char) * 1024);

	if (output_buffer == NULL)

	{
	dprintf(STDERR_FILENO,
		"Error: can't write to %s\n", output_file);
	exit(99);
	}

	return (output_buffer);
}

/**
 * close_descriptor - Closes a file descriptor.
 * @descriptor: The file descriptor to be closed.
 */
void close_descriptor(int descriptor)
{
	int result;

	result = close(descriptor);

	if (result == -1)

	{
	dprintf(STDERR_FILENO, "Error: Can't close descriptor %d\n", descriptor);
	exit(100);
	}
}

/**
 * main - Copies the contents of one file to another.
 * @argc: The number of command-line arguments.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect, exit code 97.
 *              If source file does not exist or cannot be read, exit code 98.
 *              If destination file cannot be created or written to, exit code 99.
 *              If there's an issue closing files, exit code 100.
 */
int main(int argc, char *argv[])
{
	int source_fd, destination_fd, read_bytes, written_bytes;
	char *data_buffer;

	if (argc != 3)

	{
	dprintf(STDERR_FILENO, "Usage: cp source_file destination_file\n");
exit(97);
	}

	data_buffer = allocate_buffer(argv[2]);
	source_fd = open(argv[1], O_RDONLY);
	read_bytes = read(source_fd, data_buffer, 1024);
	destination_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do

	{
	if (source_fd == -1 || read_bytes == -1)

	{
	dprintf(STDERR_FILENO,
		"Error: Can't read from source file %s\n", argv[1]);
free(data_buffer);
exit(98);
	}

	written_bytes = write(destination_fd, data_buffer, read_bytes);
	if (destination_fd == -1 || written_bytes == -1)

	{
	dprintf(STDERR_FILENO,
		"Error: Can't write to %s\n", argv[2]);
free(data_buffer);
exit(99);
	}

	read_bytes = read(source_fd, data_buffer, 1024);
	destination_fd = open(argv[2], O_WRONLY | O_APPEND);
	}

	while (read_bytes > 0);

	free(data_buffer);
	close_descriptor(source_fd);
	close_descriptor(destination_fd);

	return (0);
}
