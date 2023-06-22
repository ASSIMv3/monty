#include "monty.h"

/**
 * push - Pushes an element to the stack or queue
 * @stack: Double pointer to the stack
 * @line_number: Line number of the Monty bytecode instruction
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n;
	char *s, *invalid;

	invalid = "";
	s = strtok(NULL, "\t\n ");

	if (!s || *invalid != '\0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(s);
	if (stack_state == ELEMENT_IN_STACK)
		add_to_S(stack, n);
	else
		add_to_Q(stack, n);
}

/**
 * pall - Prints all the elements of the stack or queue
 * @stack: Double pointer to the stack
 * @line_number: Line number of the Monty bytecode instruction (unused)
 * Return: void
 */
void pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *tmp;

	if (!stack || !*stack)
		return;
	tmp = *stack;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		if (stack_state == ELEMENT_IN_STACK)
			tmp = tmp->prev;
		else
			tmp = tmp->next;
	}
}
