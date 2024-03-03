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
