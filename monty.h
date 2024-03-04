#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/* Functions prototypes */
void push(stack_t **stack, int value);
void pall(stack_t **stack);
void pint(stack_t **stack, int line_number);
void pop(stack_t **stack, int line_number);
void swap(stack_t **stack, int line_number);
void add(stack_t **stack, int line_number);
void nop(stack_t **stack, int line_number);
void nop(stack_t **stack, int line_number);
void sub(stack_t **stack, int line_number);
void div_op(stack_t **stack, unsigned int line_number);
void mul_op(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
int is_numeric(const char *str);
void process_file(const char *filename);
void process_line(char *line, int line_number, stack_t **stack);
char *my_strdup(const char *s);

#endif /* MONTY_H */
