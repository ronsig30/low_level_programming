#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and writes its content to STDOUT.
 * @filename: The name of the text file to be read.
 * @letters: The maximum number of letters (characters) to read and print.
 *
 * Return: On success, returns the actual number of bytes read and printed.
 *         Returns 0 when the function fails, the filename is NULL, or no bytes
 *         were read or printed. Returns -1 on other read or write errors.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t file_descriptor;
	ssize_t bytes_read;
	ssize_t bytes_written;

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(file_descriptor);
		return (0);
	}

	bytes_read = read(file_descriptor, buffer, letters);

	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);


	free(buffer);
	close(file_descriptor);

	if (bytes_written == -1 || (bytes_written != bytes_read && bytes_read > 0))
		return (-1);

	return (bytes_written);
}
