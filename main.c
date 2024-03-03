#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

/**
 * main - Entry point for the Monty interpreter program
 * @argc: The number of command-line arguments
 * @argv: An array containing the command-line arguments
 *
 * Return: Always returns 0
 */
int main(int argc, char *argv[])
{
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *opcode;
    char *arg;
    int line_number = 0;
    stack_t *stack = NULL;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file) != NULL)
    {
        line_number++;
        line[strcspn(line, "\n")] = '\0';

        opcode = strtok(line, " ");
        if (opcode == NULL)
            continue;

        if (strcmp(opcode, "push") == 0)
        {
            arg = strtok(NULL, " ");
            if (arg == NULL || !is_numeric(arg))
            {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                fclose(file);
                free_stack(stack);
                exit(EXIT_FAILURE);
            }
            push(&stack, atoi(arg));
        }
        else if (strcmp(opcode, "pall") == 0)
        {
            pall(&stack);
        }
        else
        {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
            fclose(file);
            free_stack(stack);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
    free_stack(stack);
    return (0);
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
        return 0;

    while (*str != '\0')
    {
        if (!isdigit(*str))
            return 0;
        str++;
    }

    return (1);
}
