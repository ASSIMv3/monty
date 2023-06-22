#include "monty.h"

/**
 * add_to_S - Adds a new element to the top of the stack
 *
 * @stack: Double pointer to the stack
 * @n: Value to be added to the new element
 *
 * Return: Pointer to the newly added element
 */
stack_t *add_to_S(stack_t **stack, int n)
{
	stack_t *new;

	new = malloc(sizeof(*new));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->prev = NULL;
	new->next = NULL;

	if (!stack || !(*stack))
		*stack = new;
	else
	{
		(*stack)->next = new;
		new->prev = (*stack);
		*stack = new;
	}

	return (new);
}

/**
 * add_to_Q - a new element to the back of the queue.
 * @stack: Double pointer to the stack.
 * @n: Value to be added to the new element.
 * Return: Pointer to the newly added element.
 */
stack_t *add_to_Q(stack_t **stack, int n)
{
	stack_t *new, *node;

	new = malloc(sizeof(*new));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->prev = NULL, new->next = NULL;

	if (!stack || !(*stack))
		*stack = new;
	else
	{
		node = *stack;
		while (node->next)
			node = node->next;
		node->next = new;
		new->prev = node;
	}

	return (new);
}
