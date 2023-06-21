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
	const char *del;
	char *opcode;

	if (!line)
		return (NULL);

	del = "\n\t ";
	opcode = strtok(line, del);
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
		{NULL, NULL}
	};
	unsigned int i;

	for (i = 0; list[i].opcode; i++)
	{
		if (strcmp(opcode, list[i].opcode) == 0)
			return (list[i].f);
	}
	return (NULL);
}
