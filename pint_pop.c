#include "monty.h"

/**
 * pint - Print the value at the top of the stack
 * @stack: Represents the stack of values
 * @line_number: Line number for error message
 */
void pint(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	if (stack && *stack)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * pop - Remove the top element of the stack and free it
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the opcode
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *popped, *new_top;

	if (stack && !(*stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (stack_state == ELEMENT_IN_STACK)
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
	popped = *stack;
	*stack = new_top;
	free(popped);
}
