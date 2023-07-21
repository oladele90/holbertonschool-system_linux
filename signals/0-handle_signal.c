#include "signals.h"

/**
 * signal_handler - prints message when SIGINT signal is sent
 * @sig: current signal
 * Return: none
*/
void signal_handler(int sig)
{
	fprintf(stdout, "Gotcha! [%d]\n", sig);
}

/**
 * handle_signal - signal handler for SIGINT
 * Return: -1 for error/ 0 for success
*/
int handle_signal(void)
{
	if (signal(SIGINT, signal_handler) == SIG_ERR)
		return (-1);

	return (0);
}
