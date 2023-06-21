#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number where the opcode is encountered
 *
 * This function adds the values of the top two elements of the stack.
 * If the stack has less than 2 elements, it prints an error message,
 * frees the stack memory, and exits with a failure status
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	/* Check if stack has less than 2 elements */
	if (stack && (!(*stack) || !(*stack)->prev))
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	/* Add top 2 elements to the top of the stack */
	(*stack)->prev->n += (*stack)->n;
	pop(stack, line_number);
}
