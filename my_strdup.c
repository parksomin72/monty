#include "monty.h"
#include <string.h>
/**
 * my_strdup - Duplicates a string
 * @s: The string to duplicate
 *
 * Return: Pointer to the duplicated string
 */
char *my_strdup(const char *s)
{
    size_t len = strlen(s) + 1;
    char *p = malloc(len);
    if (p == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    memcpy(p, s, len);
    return p;
}
