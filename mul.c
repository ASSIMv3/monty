#include "monty.h"

/**
 * mul - multiplies the second top element of the stack with the top element
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number where the opcode is encountered
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->prev)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->prev->n *= (*stack)->n;
	pop(stack, line_number);
}
