#include "monty.h"

/**
 * add_to_S - Adds a new element to the top of the stack.
 * @stack: Double pointer to the stack.
 * @n: Value to be added to the new element.
 * Return: Pointer to the newly added element.
 */
stack_t *add_to_S(stack_t **stack, int n)
{
	stack_t *new_e;

	new_e = malloc(sizeof(*new_e));
	if (!new_e)
		fprintf(stderr, "Error: malloc failed"), exit(EXIT_FAILURE);
	new_e->n = n, new_e->prev = NULL, new_e->next = NULL;

	if (!stack || !(*stack))
		*stack = new_e;
	else
	{
		(*stack)->next = new_e;
		new_e->prev = (*stack);
		*stack = new_e;
	}

	return (new_e);
}

/**
 * add_to_Q - a new element to the back of the queue.
 * @stack: Double pointer to the stack.
 * @n: Value to be added to the new element.
 * Return: Pointer to the newly added element.
 */
stack_t *add_to_Q(stack_t **stack, int n)
{
	stack_t *new_e, *node;

	new_e = malloc(sizeof(*new_e));
	if (!new_e)
		fprintf(stderr, "Error: malloc failed"), exit(EXIT_FAILURE);
	new_e->n = n, new_e->prev = NULL, new_e->next = NULL;

	if (!stack || !(*stack))
		*stack = new_e;
	else
	{
		node = *stack;
		while (node->next)
			node = node->next;
		node->next = new_e;
		new_e->prev = node;
	}

	return (new_e);
}
