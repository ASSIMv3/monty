#include "monty.h"

/**
 * free_stack - Frees a stack or queue of elements
 *
 * @stack: Pointer to the top element of the stack or queue
 *
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	if (!stack)
		return;

	if (stack_state == ELEMENT_IN_QUEUE)
	{
		temp = stack->next;
		while (stack)
		{
			free(stack);
			stack = NULL;
			stack = temp;
			if (temp)
				temp = temp->next;
		}
		return;
	}
	temp = stack->prev;
	while (stack)
	{
		free(stack);
		stack = NULL;
		stack = temp;
		if (temp)
			temp = temp->prev;
	}
}
