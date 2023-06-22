#ifndef MONTY_H
#define MONTY_H

#define IN_QUEUE 1
#define IN_STACK 0

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int struct_state;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void execute_opcode(char *instruction, unsigned int ln, stack_t **top);
char *get_opcode(char *line);
void (*instruction_func(char *opcode))(stack_t **, unsigned int);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
stack_t *add_to_S(stack_t **stack, int n);
stack_t *add_to_Q(stack_t **stack, int n);
ssize_t custom_getline(char **b, size_t *n, int fd);
void free_stack(stack_t *stack);
int custom_read(char *b, unsigned int size, int fd);
size_t line_size(char *b, int i);
int fill_b(char *buffer, int i, char **b, size_t *n, int fd, size_t size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void pint(stack_t **stack, __attribute__((unused))unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
stack_t *stack_top(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void division(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void modulo(stack_t **stack, unsigned int line_number);
void print_char(stack_t **stack, unsigned int line_number);
void print_str(stack_t **stack, unsigned int line_number);
unsigned int flushBuffer(char *buffer);
void rotate(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
