#include "monty.h"

/**
 * stack_top - Get the top element of the stack and update the stack
 *
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the stack_top instruction
 *
 * Return: Pointer to the top element of the stack
 */
stack_t *stack_top(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	stack_t *top, *new_top;

	if (struct_state == IN_STACK)
	{
		new_top = (*stack)->prev;
		if (new_top)
			new_top->next = NULL;
	}
	else
	{
		new_top = (*stack)->next;
		if (new_top)
			new_top->prev = NULL;
	}
	top = *stack;
	*stack = new_top;
	return (top);
}
