#include "main.h"

/**
 * create_file - Creates a file
 * @filename: The name of the file to create.
 * @text_content: The text content to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */

int create_file(const char *filename, char *text_content)
{
	int bytes_written = 0;

	if (filename == NULL)
	return (-1);

if (text_content != NULL)
{
	while (text_content[bytes_written] != '\0')
	bytes_written++;

if (write(open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600), text_content, bytes_written) == -1)
{
return (-1);
}
}
else
{
	if (open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600) == -1)
	{
	return (-1);
	}
}
return (1);
}
