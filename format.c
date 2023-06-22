#include "monty.h"

/**
 * to_stack - sets the format of the data to a stack
 *
 * @stack: Double pointer to the stack
 * @line_number: Line number of the instruction
 *
 * Return: void
 */
void to_stack(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *node1, *node2, *lagging;

	if (struct_state == IN_QUEUE)
	{
		if (*stack && (*stack)->next)
		{
			lagging = *stack;
			node1 = (*stack)->next;
			while (node1)
			{
				node2 = node1->next;

				lagging->prev = node1;
				node1->next = lagging;

				lagging = node1;
				node1 = node2;
			}
			lagging->prev = NULL;
		}
		struct_state = IN_STACK;
	}
}

/**
 * to_queue - sets the format of the data to a queue
 *
 * @stack: Double pointer to the stack
 * @line_number: Line number of the instruction
 *
 * Return: void
 */
void to_queue(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *node1, *node2, *lagging;

	if (struct_state == IN_STACK)
	{
		if (*stack && (*stack)->prev)
		{
			lagging = *stack;
			node1 = (*stack)->prev;
			while (node1)
			{
				node2 = node1->prev;

				lagging->next = node1;
				node1->prev = lagging;

				lagging = node1;
				node1 = node2;
			}
			lagging->next = NULL;
		}
		struct_state = IN_QUEUE;
	}
}
