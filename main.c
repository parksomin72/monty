#include "monty.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    stack_t *stack = NULL;
    char *opcode;
    int value;

    // Read each line of the file
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file)) != -1)
    {
        // Tokenize the line
        opcode = strtok(line, " \n");
        if (!opcode)
            continue;

        if (strcmp(opcode, "push") == 0)
        {
            // Extract integer argument for push
            char *arg = strtok(NULL, " \n");
            if (!arg)
            {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }
            value = atoi(arg);
            push(&stack, value);
        }
        else if (strcmp(opcode, "pall") == 0)
        {
            pall(&stack);
        }
        else
        {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }
    }

    free(line);
    fclose(file);
    return EXIT_SUCCESS;
}
