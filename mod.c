#include "monty.h"

/**
 * modulo - calculate the modulus of the second top element
 * of the stack with the top element
 *
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number where the opcode is encountered
 *
 * Return: void
 */
void modulo(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (stack && *stack && (*stack)->prev)
	{
		top = stack_top(stack, line_number);
		if (top->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}
		(*stack)->n = (*stack)->n % top->n;
		free(top);
	}
	else
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
