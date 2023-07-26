#include "signals.h"
/**
 * handle_sig - Signal handler function for SIGINT.
 * @sig: The signal number caught (SIGINT).
 */
void handle_sig(int sig)
{
	printf("Caught %d\n", sig);
	fflush(stdout);
	exit(EXIT_SUCCESS);
}

/**
 * handle_sigaction - Set a signal handler for SIGINT using sigaction.
 * Return: On success, returns 0. On error, returns -1.
 *
 */
int handle_sigaction(void)
{
	struct sigaction sam;

	sam.sa_handler = handle_sig;
	return (sigaction(SIGINT, &sam, NULL));
}

/**
 * main - Entry point of the program.
 * Return: Always returns EXIT_SUCCESS.
 */

int main(void)
{
	if (handle_sigaction() == -1)
	{
		printf("Failure\n");
		return (EXIT_FAILURE);
	}
	while (1)
	{
		sleep(1);
	}
	return (EXIT_SUCCESS);
}
