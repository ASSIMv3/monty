#include "monty.h"

/**
 * print_char -  Prints the character at the top of the stack
 *
 * @stack: Double pointer to the stack
 * @line_number: Line number of the instruction
 *
 * Return: void
 */
void print_char(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n > 127 || (*stack)->n < 0)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
