#include "signals.h"

/**
 * handle_sig - Signal handler function for SIGQUIT.
 * @sig: The signal number caught (unused).
 */

void handle_sig(int sig)
{
	(void)sig;
	printf("SIGQUIT sent by %d\n", getppid());
	fflush(stdout);
}

/**
 * trace_signal_sender - Set a signal handler for SIGQUIT using sigaction.
 * Return: On success, returns 0. On error, returns -1.
 */

int trace_signal_sender(void)
{
	struct sigaction sa;

	sa.sa_handler = handle_sig;

	return (sigaction(SIGQUIT, &sa, NULL));
}

