#include "monty.h"

/**
 * division - Divide the second top element of the stack by the top element
 *
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the divide instruction
 *
 * Return: void
 */
void division(stack_t **stack, unsigned int line_number)
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
		(*stack)->n = (*stack)->n / top->n;
		free(top);
	}
	else
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
