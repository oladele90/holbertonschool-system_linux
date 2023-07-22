#include "signals.h"

/**
 * current_handler_sigaction - Retrieves current signal handler for SIGINT.
 *
 * Return: A function pointer to the original signal handler for SIGINT.
 */

void (*current_handler_sigaction(void))(int)
{
	struct sigaction sa;

	if (sigaction(SIGINT, NULL, &sa) == -1)
		return (NULL);

	return (sa.sa_handler);
}
