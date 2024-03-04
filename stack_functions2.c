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

/**
 * mul_op - Multiplies the second top element of the stack with the top element.
 * @stack: Double pointer to the stack
 * @line_number: Line number in the Monty file
 */
void mul_op(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n *= (*stack)->n;
    temp = *stack;
    *stack = (*stack)->next;
    free(temp);
}

/**
 * mod_op - Computes the rest of the division of the second top element
 *           of the stack by the top element of the stack.
 * @stack: Double pointer to the stack
 * @line_number: Line number in the Monty file
 */
void mod_op(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;
    int divisor;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    divisor = (*stack)->n;
    if (divisor == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n %= divisor;
    temp = *stack;
    *stack = (*stack)->next;
    free(temp);
}

/**
 * pchar - Prints the character at the top of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number in the Monty file
 */
void pchar(stack_t **stack, int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n < 0 || (*stack)->n > 127)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%c\n", (*stack)->n);
}

/**
 * pstr - Prints the string starting at the top of the stack.
 * @stack: Double pointer to the stack
 * @line_number: Line number in the Monty file
 */
void pstr(stack_t **stack, int line_number)
{
    stack_t *temp = *stack;

    while (temp != NULL && temp->n != 0)
    {
        if (temp->n < 0 || temp->n > 127)
        {
            fprintf(stderr, "L%d: can't pstr, value out of range\n", line_number);
            exit(EXIT_FAILURE);
        }
        putchar(temp->n);
        temp = temp->next;
    }
     putchar('\n');

}
