#include "sockets.h"

void requst_breakdown_printout(void *message)
{
    char *path = NULL, *line = NULL;
    char *brk = "\r\n";

    line = strtok(message, brk);
    path = strtok(line, " ");
    printf("%s\n", path);
    fflush(stdout);
}