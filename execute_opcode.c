#include "monty.h"

/**
 * execute_opcode - Executes a Monty bytecode instruction
 *
 * @instruction: The instruction to be executed
 * @ln: The line number of the instruction
 * @top: A double pointer to the top of the stack
 *
 * Return: void
 */
void execute_opcode(char *instruction, unsigned int ln, stack_t **top)
{
	char *opcode;
	void (*f)(stack_t **, unsigned int);

	opcode = get_opcode(instruction);
	if (opcode && strchr(opcode, '#') != NULL)
	{
		/* Remove the comment by null-terminating at the '#' symbol */
		*strchr(opcode, '#') = '\0';
	}
	if (opcode && *opcode != '\0')
	{
		f = instruction_func(opcode);
		if (!f)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", ln, opcode);
			exit(EXIT_FAILURE);
		}

		f(top, ln);
	}
}
