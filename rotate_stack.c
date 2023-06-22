#include "monty.h"

/**
 * rotate_l - Rotates the stack to the top
 *
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number where the opcode is encountered
 *
 * Return: void
 */
void rotate_l(stack_t **stack,
		 __attribute__((unused)) unsigned int line_number)
{
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

/**
 * rotate_r -  rotates the stack to the bottom
 *
 * @stack: Double pointer to the stack
 * @line_number: Line number of the instruction
 *
 * Return: void
 */
void rotate_r(stack_t **stack,
		__attribute__((unused))unsigned int line_number)
{
	stack_t *last;

	if (!stack || !(*stack) || !(*stack)->prev)
		return;

	/* get last element */
	last = *stack;
	while (last && last->prev)
		last = last->prev;

	/* rotate */
	last->next->prev = NULL;
	last->prev = *stack;
	last->next = NULL;
	(*stack)->next = last;

	/* change TOS */
	*stack = last;
}
