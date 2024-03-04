#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * rotr - Rotates the stack to the bottom.
 * @stack: Double pointer to the stack
 * @line_number: Line number in the Monty file (unused parameter)
 */
void rotr(stack_t **stack, int line_number)
{
    stack_t *temp;
    (void)line_number;

    if (*stack == NULL || (*stack)->next == NULL)
        return;

    temp = *stack;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = *stack;
    (*stack)->prev = temp;
    *stack = temp;
    temp->prev->next = NULL;
    temp->prev = NULL;
}

/**
 * stack - Sets the format of the data to a stack (LIFO)
 * @stack: Double pointer to the stack
 * @line_number: Line number in the Monty file
 */
void stack(stack_t **stack, int line_number)
{
    (void)stack;
    (void)line_number;
    mode = STACK;
}

/**
 * queue - Sets the format of the data to a queue (FIFO)
 * @stack: Double pointer to the stack
 * @line_number: Line number in the Monty file
 */
void queue(stack_t **stack, int line_number)
{
    (void)stack;
    (void)line_number;
    mode = QUEUE;
}
