#ifndef SIGNALS_H
#define SIGNALS_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <time.h>

int handle_signal(void);
void (*current_handler_signal(void))(int);
/*void handle_sig(int sig);*/
int handle_sigaction(void);
#endif
