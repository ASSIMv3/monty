#include "monty.h"

/**
 * main - Entry point for the Monty interpreter
 * @ac: Number of command-line arguments
 * @av: Array of command-line arguments
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	int fd;
	char *buffer = NULL;
	size_t i = 0;
	unsigned int line_number = 1;
	stack_t *top = NULL;

	struct_state = IN_STACK;
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&buffer, &i, fd) != -1)
	{
		execute_opcode(buffer, line_number, &top);
		line_number++;
	}

	free(buffer);
	free_stack(top);

	close(fd);
	return (0);
}
