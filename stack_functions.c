#include "monty.h"
#include <stdlib.h>

/**
 * free_stack - Frees a stack.
 * @stack: Pointer to the top of the stack
 *
 * This function frees all the nodes in the stack.
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
/**
 * push - Pushes an element onto the stack.
 * @stack: Double pointer to the stack
 * @value: Value to be pushed onto the stack
 */
void push(stack_t **stack, int value)
{
        stack_t *new_node = malloc(sizeof(stack_t));

        if (!new_node)
        {
                fprintf(stderr, "Error: malloc failed\n");
                exit(EXIT_FAILURE);
        }

        new_node->n = value;
        new_node->prev = NULL;
        new_node->next = *stack;

        if (*stack)
                (*stack)->prev = new_node;

        *stack = new_node;
}
/**
 * pall - Prints all the values on the stack.
 * @stack: Double pointer to the stack
 */
void pall(stack_t **stack)
{
        stack_t *temp = *stack;

        while (temp)
        {
                printf("%d\n", temp->n);
                temp = temp->next;
        }
}
/**
 * pint - Prints the value at the top of the stack.
 * @stack: Double pointer to the stack
 * @line_number: Line number in the Monty file
 */
void pint(stack_t **stack, int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}
/**
 * pop - Removes the top element of the stack.
 * @stack: Double pointer to the stack
 * @line_number: Line number in the Monty file
 */
void pop(stack_t **stack, int line_number)
{
    stack_t *temp;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    *stack = (*stack)->next;
    if (*stack != NULL)
    {
        (*stack)->prev = NULL;
    }

    free(temp);
}
/**
 * swap - Swaps the top two elements of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number in the Monty file
 */
void swap(stack_t **stack, int line_number)
{
    stack_t *temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = (*stack)->next;
    (*stack)->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = *stack;
    temp->prev = NULL;
    temp->next = *stack;
    (*stack)->prev = temp;
    *stack = temp;
}
