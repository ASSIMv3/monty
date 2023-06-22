#include "monty.h"

#define BUFF_SIZE 1024

/**
 * custom_getline - Custom implementation of the getline function
 *
 * @buf: Pointer to the buffer that will store the line
 * @n: Pointer to the size of the buffer
 * @file: File descriptor to read from
 *
 * Return: the number of characters read | -1 (Failure)
 */
ssize_t custom_getline(char **buf, size_t *n, int file)
{
	static char buffer[BUFF_SIZE];
	static int i;
	size_t size;

	if (i == 0 || i >= BUFF_SIZE || buffer[i] == '\0')
	{
		if (custom_read(buffer, BUFF_SIZE, file) == 0)
			return (-1);
		i = 0;
	}

	if (buf && (*buf))
	{
		free(*buf);
		*buf = NULL;
	}
	size = line_size(buffer, i) + 1;
	*buf = malloc(sizeof(char) * size);
	if (!(*buf))
		fprintf(stderr, "Error: malloc failed\n"), exit(EXIT_FAILURE);

	*n = 0;
	i = fill_buff(buffer, i, buf, n, file, size);
	++i;

	return (1);
}

/**
 * custom_read - reads content from file
 * @buf: buffer to be filled
 * @size: buffer size
 * @file: file descriptor
 *
 * Return: number of characters read
 */
int custom_read(char *buf, unsigned int size, int file)
{
	unsigned int j;
	int ret_val;

	j = 0;
	while (j < size)
	{
		buf[j] = '\0';
		j++;
	}

	ret_val = read(file, buf, size);
	if (ret_val == -1)
	{
		fprintf(stderr, "Error: read failed\n");
		exit(EXIT_FAILURE);
	}

	return (ret_val);
}

/**
 * line_size - counts a line's size of characters
 *
 * @buf: buffer
 * @idx: starting index
 *
 * Return: number of characters in a line
 */
size_t line_size(char *buf, int idx)
{
	size_t size;

	size = 0;
	while ((idx < BUFF_SIZE) && buf[idx] && buf[idx] != '\n')
	{
		size++;
		idx++;
	}

	return (size);
}

/**
 * fill_buff - fills buffer 'buf' with a line from 'buffer'
 *
 * @buffer: buffer containing content
 * @idx: starting index of buffer
 * @buf: pointer to buffer to be filled
 * @n: pointer to buf's index
 * @file: file desciptor
 * @size: buf old size
 *
 * Return: new position of idx
 */
int fill_buff(char *buffer, int idx, char **buf, size_t *n,
		int file, size_t size)
{
	size_t new_size;

	new_size = 0;
	for (; buffer[idx] != '\n'; idx++)
	{
		if (idx >= BUFF_SIZE)
		{
			if (custom_read(buffer, BUFF_SIZE, file) == 0)
				break;
			idx = 0;

			new_size = size + line_size(buffer, idx);
			(*buf) = custom_realloc(*buf, size, new_size);
			idx = -1;
		}
		else
			(*buf)[(*n)++] = buffer[idx];
	}
	(*buf)[(*n)] = '\0';

	return (idx);
}
