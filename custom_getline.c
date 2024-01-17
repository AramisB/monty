#include "monty.h"

/**
 * read_line - a function that reads a line from the given file stream
 * into a fixed-size buffer
 * @buffer: buffer to store the line
 * @size: size of the buffer
 * @stream: file stream to read from.
 *
 * Return: number of characters read, or -1 on failure or EOF
 */
ssize_t read_line(char *buffer, size_t size, FILE *stream)
{
	int chara;
	size_t i = 0;

	if (buffer == NULL || stream == NULL)
	{
		return (-1);
	}
	while (i < (size - 1) && (chara = fgetc(stream)) != EOF && chara != '\n')
	{
		buffer[i++] = chara;
	}
	if (chara == EOF && i == 0)
	{
		return (-1);
	}
	buffer[i] = '\0';
	return (i);
}
