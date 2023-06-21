#include "monty.h"

/**
 * free_stack - Frees memory allocated for the stack
 * @stack: Pointer to the top element of the stack
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *next_e;

	if (!stack)
		return;

	if (struct_state == IN_QUEUE)
	{
		next_e = stack->next;
		while (stack)
		{
			free(stack), stack = NULL;
			stack = next_e;
			if (next_e)
				next_e = next_e->next;
		}
		return;
	}
	next_e = stack->prev;
	while (stack)
	{
		free(stack), stack = NULL;
		stack = next_e;
		if (next_e)
			next_e = next_e->prev;
	}
}
