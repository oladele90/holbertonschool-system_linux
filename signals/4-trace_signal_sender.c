#include "signals.h"

void handle_sig(int sig)
{
    (void)sig;
	printf("SIGQUIT sent by %d\n", getppid());
	fflush(stdout);
}

int trace_signal_sender(void)
{
	struct sigaction sa;
	sa.sa_handler = handle_sig;

	return (sigaction(SIGQUIT, &sa, NULL));

}

