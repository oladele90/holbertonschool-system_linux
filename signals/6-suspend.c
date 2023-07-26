#include "signals.h"
/**
 * handle_sig - Signal handler function for SIGINT.
 * @sig: The signal number caught (SIGINT).
 */
void handle_sig(int sig)
{
	printf("Caught %d\nSignal received\n", sig);
	fflush(stdout);
}

/**
 * main - Entry point of the program.
 * Return: Always returns EXIT_SUCCESS.
 */

int main(void)
{
	struct sigaction sam;

	sam.sa_handler = handle_sig;
	sigaction(SIGINT, &sam, NULL);
	pause();
	return (EXIT_SUCCESS);
}
