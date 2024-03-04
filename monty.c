#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
MontyData global;

/**
 * process_line - Process each line of the input file
 * @line: The line to be processed
 * @line_number: The line number in the file
 * @stack: Double pointer to the stack
 */
void process_line(char *line, int line_number, stack_t **stack)
{
    char *opcode;
    char *arg;
    char *comment_ptr;

    while (*line == ' ')
        line++;

    if (*line == '\0' || *line == '#')
        return;

    comment_ptr = strchr(line, '#');
    if (comment_ptr != NULL)
        *comment_ptr = '\0';

    opcode = strtok(line, " \n");
    if (opcode == NULL)
        return;
    if (strcmp(opcode, "nop") == 0)
        return;
    if (strcmp(opcode, "push") == 0)
    {
        arg = strtok(NULL, " \n");
        if (arg == NULL || !is_numeric(arg))
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
        push(stack, atoi(arg));
    }
    else if (strcmp(opcode, "pint") == 0)
    {
        pint(stack, line_number);
    }
    else if (strcmp(opcode, "pall") == 0)
    {
        pall(stack, line_number);
    }
    else if (strcmp(opcode, "pop") == 0)
    {
        pop(stack, line_number);
    }
    else if (strcmp(opcode, "swap") == 0)
    {
        swap(stack, line_number);
    }
    else if (strcmp(opcode, "add") == 0)
    {
        add(stack, line_number);
    }
    else if (strcmp(opcode, "sub") == 0)
    {
        sub(stack, line_number);
    }
    else if (strcmp(opcode, "div") == 0)
    {
        div_op(stack, line_number);
    }
    else if (strcmp(opcode, "mul") == 0)
    {
        mul_op(stack, line_number);
    }
    else if (strcmp(opcode, "mod") == 0)
    {
        mod_op(stack, line_number);
    }
    else if (strcmp(opcode, "pchar") == 0)
    {
        pchar(stack, line_number);
    }
    else if (strcmp(opcode, "pstr") == 0)
    {
        pstr(stack, line_number);
    }
    else if (strcmp(opcode, "rotl") == 0)
    {
    rotl(stack, line_number);
    }
    else if (strcmp(opcode, "rotr") == 0)
    {
        rotr(stack, line_number);
    }
    else if (strcmp(opcode, "stack") == 0)
    {
        mode = STACK;
    }
    else if (strcmp(opcode, "queue") == 0)
    {
        mode = QUEUE;
    }
    else
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
        exit(EXIT_FAILURE);
    }
}


/**
 * process_file - Processes the lines of a file.
 * @filename: The name of the file to process
 *
 * This function reads each line of the specified file, processes it, and
 * performs the corresponding stack operation.
 */
void process_file(const char *filename)
{
    FILE *file;
    char line[MAX_LINE_LENGTH];
    int line_number = 0;
    stack_t *stack = NULL;

    file = fopen(filename, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file) != NULL)
    {
        line_number++;
        line[strcspn(line, "\n")] = '\0';
        process_line(line, line_number, &stack);
    }

    fclose(file);
    free_stack(stack);
}
/**
 * is_numeric - Checks if a string is a valid numeric value
 * @str: The string to check
 *
 * Return: 1 if the string is numeric, 0 otherwise
 */
int is_numeric(const char *str)
{
    if (str == NULL || *str == '\0')
        return (0);

    while (*str != '\0')
    {
        if (!isdigit(*str) && *str != '-')
            return (0);
        str++;
    }

    return (1);
}
/**
 * main - Entry point for the Monty interpreter program
 * @argc: The number of command-line arguments
 * @argv: An array containing the command-line arguments
 *
 * Return: Always returns 0
 */
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    global.value = "10";

    process_file(argv[1]);

    return (0);
}

/**
 * add - Adds the top two elements of the stack.
 * @stack: Double pointer to the stack
 * @line_number: Line number in the Monty file
 */
void add(stack_t **stack, int line_number)
{
    stack_t *temp;

    /* Check if there are at least two elements in the stack */
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* Perform operations based on the current mode */
    if (mode == STACK)
    {
        /* Add elements in stack mode */
        (*stack)->next->n += (*stack)->n;
        temp = *stack;
        *stack = (*stack)->next;
        free(temp);
        (*stack)->prev = NULL;
    }
    else if (mode == QUEUE)
    {
        /* Add elements in queue mode */
        stack_t *last = *stack;
        stack_t *second_last = NULL;

        /* Traverse to the last and second last elements */
        while (last->next != NULL)
        {
            second_last = last;
            last = last->next;
        }

        /* Add the top two elements */
        last->n += (*stack)->n;

        /* Remove the previous top element */
        free(*stack);

        /* Update the stack pointer to point to the second element */
        *stack = last;
        last->prev = NULL;
        second_last->next = NULL;
    }
}
