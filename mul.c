#include "monty.h"

/**
 * mul - multiplies the second top element of the stack with the top element of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number where the opcode is encountered
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	/* Check if the stack is not empty and contains at least two elements */
	if (stack && (!(*stack) || !(*stack)->prev))
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	/* Multiply the top two elements in the stack */
	(*stack)->prev->n *= (*stack)->n;
	/* Pop the top element from the stack */
	pop(stack, line_number);
}
