#include "sockets.h"

void requst_breakdown_printout(void *message)
{
    char *path = NULL;
    char *brk = "\r\n";

    path = strtok(message, brk);
    path = strtok(NULL, brk);
    printf("%s\n", path);
    fflush(stdout);
}