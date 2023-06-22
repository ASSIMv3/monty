#include "monty.h"

/**
 * rotate - Rotates the stack to the top, moving the top element to the bottom
 *
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number where the opcode is encountered
 *
 * Return: void
 */
void rotate(stack_t **stack, unsigned int line_number)
{
	stack_t *node, *popped;

	if (stack && *stack && (*stack)->prev)
	{
		stack_t *top = *stack;
		stack_t *second_top = (*stack)->prev;

		/* Find the last node in the stack */
		stack_t *last = top;

		while (last->prev)
			last = last->prev;

		/* Perform the rotation */
		last->prev = top;
		top->next = last;
		top->prev = NULL;

		second_top->next = NULL;
		*stack = second_top;
	}
}
