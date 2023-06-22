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
		popped = stack_top(stack, line_number);
		node = *stack;
		while (node->prev)
			node = node->prev;
		node->prev = popped;
		popped->next = node;
		popped->prev = NULL;
	}
}
