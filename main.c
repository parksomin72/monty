#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[])
{
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *opcode;
    char *arg;
    int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: monty file\n");
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
            if (arg == NULL)
            {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }
            printf("Pushing %s\n", arg);
        }
        else if (strcmp(opcode, "pop") == 0)
        {
            printf("Popping\n");
        }
        else if (strcmp(opcode, "add") == 0)
        {
            printf("Adding\n");
        }
    }

    fclose(file);

    return (0);
}
