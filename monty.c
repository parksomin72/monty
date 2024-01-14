#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "monty.h"

data_t *data;


void monty_interpreter(FILE *file)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 0;
    stack_t *stack = NULL; /* Assuming you have a global stack variable */
    char *opcode;

    while ((read = getline(&line, &len, file)) != -1)
    {
        line_number++;

        /* Tokenize the line to get opcode */
        opcode = strtok(line, " \t\n");

        if (opcode != NULL)
        {
            /* Get the corresponding instruction function */
            instruction_t *instruction = get_instruction(opcode);

            if (instruction)
            {
                /* Call the instruction function with the stack and line_number */
                instruction->f(&stack, line_number);
            }
            else
            {
                fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
                free(line);
                exit(EXIT_FAILURE);
            }
        }
    }

    /* Free dynamically allocated memory */
    free(line);
}

instruction_t instructions[] = {
    {"push", push},
    {"pall", pall},
    {NULL, NULL} /* Terminate the array */
};

instruction_t *get_instruction(char *opcode)
{
    int i;
    for (i = 0; instructions[i].opcode != NULL; i++)
    {
        if (strcmp(instructions[i].opcode, opcode) == 0)
            return &instructions[i];
    }
    return NULL; /* Opcode not found */
}


/**
 * push - Pushes an element onto the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void push(stack_t **stack, unsigned int line_number)
{
    int value;
    stack_t *new_node;

    /* Check if there is an argument following the push opcode */
    if (!data || !data->arg)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* Convert the argument to an integer using atoi */
    value = atoi(data->arg);

    /* Create a new node for the stack */

    new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    /* Set the value of the new node */
    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    /* Update the previous pointer of the previous top node */
    if (*stack)
        (*stack)->prev = new_node;

    /* Set the stack pointer to the new node */
    *stack = new_node;
}

/**
 * pall - Prints all values on the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)stack;
	(void)line_number;

	current = *stack;


	while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
