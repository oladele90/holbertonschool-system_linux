#include "signals.h"

void (*current_handler_signal(void))(int)
{
    void (*current_handler)(int);
	current_handler = signal(SIGINT, SIG_DFL);
    signal(SIGINT, current_handler);
    return (current_handler);
}
