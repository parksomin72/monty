#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mode = STACK;
MontyData global;
/*char *global_value = NULL;*/

/**
 * push - Pushes an element to the stack or queue
 * @stack: Double pointer to the stack
 * @line_number: Line number in the Monty file
 */
void push(stack_t **stack, int line_number)
{
	stack_t *new_node;

	if (global.value != NULL)
	{
    if (!stack)
    {
        fprintf(stderr, "L%d: stack not found\n", line_number);
        exit(EXIT_FAILURE);
    }

    new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = atoi(global.value);
    new_node->next = NULL;

    if (*stack == NULL)
    {
        new_node->prev = NULL;
        *stack = new_node;
    }
    else
    {
        if (mode == STACK)
        {
            new_node->prev = NULL;
            (*stack)->prev = new_node;
            new_node->next = *stack;
            *stack = new_node;
        }
        else if (mode == QUEUE)
        {
            stack_t *temp = *stack;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = new_node;
            new_node->prev = temp;
        }
    }
	}
    else
    {
        fprintf(stderr, "Error: Global value not set\n");
        exit(EXIT_FAILURE);
    }
}

/**
 * pall - Prints all the values on the stack, starting from the top
 * @stack: Pointer to the stack
 * @line_number: Line number in the Monty file
 */
void pall(stack_t **stack, int line_number)
{
	stack_t *temp;
    (void)line_number;

    temp = *stack;

    while (temp != NULL)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
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
