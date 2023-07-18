#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "libasm.h"

#define S1  "Holberton School"
#define S2  "School"
#define S3  "Socool"

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    char *x, *y;
    x = asm_strstr(S1, S2);
    y = strstr(S1, S2);
    printf("%s, %s\n", x, y);
    assert(strstr(S1, S2) == asm_strstr(S1, S2));
    x = asm_strstr(S1, S3);
    
    printf("%s, , , %s\n", x, x);
    assert(strstr(S1, S3) == asm_strstr(S1, S3));
    x = asm_strstr(S1, S1);
    y = strstr(S1, S1);
    printf("%s,, %s\n", x, y);
    assert(strstr(S1, S1) == asm_strstr(S1, S1));

    printf("All good!\n");
    return (EXIT_SUCCESS);
}
