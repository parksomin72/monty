#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
int main(int argc, char *argv[])
{
	FILE *file;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    /* Initialize any necessary variables or data structures */

    /* Call your interpreter function with the opened file */
    monty_interpreter(file);

    fclose(file);
    return EXIT_SUCCESS;
}
