#include "signals.h"

/**
 * current_handler_signal - Retrieves current signal handler for SIGINT.
 *
 * Return: A function pointer to the original signal handler for SIGINT.
 */

void (*current_handler_signal(void))(int)
{
	void (*current_handler)(int);

	current_handler = signal(SIGINT, SIG_DFL);
	signal(SIGINT, current_handler);
	return (current_handler);
}
