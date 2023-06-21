#include "monty.h"

/**
 * pint - Print the value at the top of the stack
 * @stack: Represents the stack of values
 * @line_number: Line number for error message
 */
void pint(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	if (stack && *stack)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
