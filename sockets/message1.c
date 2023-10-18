#include "sockets.h"

void requst_breakdown_printout(void *message)
{
    char *path = NULL;
    char *brk = "\r\n";

    strtok(message, brk);
    path = strtok(path, " ");
    printf("%s\n", path);
    fflush(stdout);
}