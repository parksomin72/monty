#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * nop - Doesn't do anything.
 * @stack: Double pointer to the stack
 * @line_number: Line number in the Monty file
 */
void nop(stack_t **stack, int line_number)
{
    (void) stack;
    (void) line_number;
}

/**
 * sub - Subtracts the top element of the stack from the second top element.
 * @stack: Double pointer to the stack
 * @line_number: Line number in the Monty file
 */
void sub(stack_t **stack, int line_number)
{
    stack_t *temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n -= (*stack)->n;
    temp = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    free(temp);
}

/**
 * div_op - Divides the second top element of the stack by the top element.
 * @stack: Double pointer to the stack
 * @line_number: Line number in the Monty file
 */
void div_op(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n /= (*stack)->n;
    temp = *stack;
    *stack = (*stack)->next;
    free(temp);
}
