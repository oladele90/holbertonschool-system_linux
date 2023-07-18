#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "libasm.h"

#define S1	""
#define S2	""
#define N	1

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    int x, y;
    x = strncmp(S1, S2, N);
    y = asm_strncmp(S1, S2, N);
    printf("%d, %d\n", x, y);
	assert(strncmp(S1, S2, N) == asm_strncmp(S1, S2, N));

	printf("All good!\n");
	return (EXIT_SUCCESS);
}