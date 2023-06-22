#include "monty.h"

/**
 * sub - Subtracts the top element from the second top element of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the instruction in the script
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (stack && (!(*stack) || !(*stack)->prev))
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	/* Subtract the top element from the second top element and update TOS */
	(*stack)->prev->n -= (*stack)->n;
	pop(stack, line_number);
}
