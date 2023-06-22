#include "monty.h"

/**
 * get_opcode - Get the opcode from a line of Monty bytecode
 *
 * @line: The line of Monty bytecode
 *
 * Return: A pointer to the extracted opcode string | NULL (line is NULL)
 */
char *get_opcode(char *line)
{
	const char *delim;
	char *opcode;

	if (!line)
		return (NULL);

	delim = "\n\t ";
	opcode = strtok(line, delim);
	return (opcode);
}

/**
 * instruction_func - Get the function pointer for a given opcode
 *
 * @opcode: The opcode for which to retrieve the function pointer
 *
 * Return: The function pointer corresponding to the given opcode | NULL
 */
void (*instruction_func(char *opcode))(stack_t **, unsigned int)
{
	instruction_t list[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", division},
		{"mul", mul},
		{"mod", modulo},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotate_l},
		{"rotr", rotate_r},
		{"stack", to_stack},
		{"queue", to_queue},
		{NULL, NULL}
	};
	unsigned int idx = 0;

	while (list[idx].opcode)
	{
		if (strcmp(opcode, list[idx].opcode) == 0)
			return (list[idx].f);
		idx++;
	}
	return (NULL);
}
