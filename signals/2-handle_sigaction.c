#include "signals.h"
/**
 * handle_sig - Signal handler function for SIGINT.
 * @sig: The signal number caught (SIGINT).
 */
void handle_sig(int sig)
{
	printf("Gotcha! [%d]\n", sig);
	fflush(stdout);
}

/**
 * handle_sigaction - Set a signal handler for SIGINT using sigaction.
 * Return: On success, returns 0. On error, returns -1.
 *
 */
int handle_sigaction(void)
{
	struct sigaction sa;

	sa.sa_handler = handle_sig;
	return (sigaction(SIGINT, &sa, NULL));
}
