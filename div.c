#include "monty.h"

/**
 * divide - divides the second top element of the stack by the top element of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the instruction in the script
 */
void divide(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (stack && *stack && (*stack)->prev)
	{
		top = pop2(stack, line_number);
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
