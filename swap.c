#include "monty.h"

/**
 * swap - Swap the top two elements of the stack
 *
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the swap instruction
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tos_node, *next_tos;

	if (*stack && (*stack)->prev)
	{
		tos_node = stack_top(stack, line_number);
		next_tos = *stack;
		if (stack_state == ELEMENT_IN_STACK)
		{
			tos_node->prev = next_tos->prev;
			if (next_tos->prev)
				next_tos->prev->next = tos_node;
			tos_node->next = next_tos;
			next_tos->prev = tos_node;
		}
	}
	else
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
