#include "monty.h"

/**
 * print_str - prints the string starting at the top of the stack
 *
 * @stack: Double pointer to the stack
 * @line_number: Line number of the instruction (unused)
 *
 * Return: void
 */
void print_str(stack_t **stack,
		__attribute__((unused))unsigned int line_number)
{
	unsigned int i;
	char buffer[100];
	stack_t *tmp;

	i = 0;
	if (stack && *stack)
		tmp = *stack;
	else
		tmp = NULL;
	while (tmp)
	{
		/* check if buffer is full */
		if (i >= 99)
			i = flushBuffer(buffer);

		/* fill buffer */
		if (tmp->n < 1 || tmp->n > 127)
			break;
		buffer[i++] = tmp->n;

		tmp = tmp->prev;
	}

	buffer[i++] = '\n';
	write(STDOUT_FILENO, buffer, i);
}

/**
 * flushBuffer - Flushes the buffer and prints its contents
 *
 * @buffer: Buffer containing characters to be printed
 *
 * Return: 0 after flushing the buffer
 */
unsigned int flushBuffer(char *buffer)
{
	int i;

	write(STDOUT_FILENO, buffer, 100);
	for (i = 0; i <= 100; i++)
		buffer[i] = '\0';
	return (0);
}
