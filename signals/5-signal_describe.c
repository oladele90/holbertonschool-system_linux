#include "signals.h"

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments (including the program name).
 * @argv: An array of strings representing the command-line arguments.
 * Return: 0 on success, or an appropriate error code on failure.
 */
int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Usage: %s <signum>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	printf("%s: %s\n", argv[1], strsignal(atoi(argv[1])));
	return (0);
}
