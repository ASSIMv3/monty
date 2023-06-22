#include "monty.h"

/**
 * main - Entry point
 *
 * @argc: Arguments count
 * @argv: Arguments vector
 *
 * Return: 0 (Success)
 */
int main(int argc, char **argv)
{
	int file;
	char *buffer = NULL;
	size_t i = 0;
	unsigned int line_num = 1;
	stack_t *top = NULL;

	stack_state = ELEMENT_IN_STACK;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = open(argv[1], O_RDONLY);
	if (file == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (custom_getline(&buffer, &i, file) != -1)
	{
		execute_opcode(buffer, line_num, &top);
		line_num++;
	}

	free(buffer);
	free_stack(top);

	close(file);
	return (0);
}
