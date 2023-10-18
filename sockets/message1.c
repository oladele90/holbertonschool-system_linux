#include "sockets.h"

void requst_breakdown_printout(void *message)
{
    char *path = NULL, *line = NULL, *method = NULL;
    char *brk = "\r\n";

    line = strtok(message, brk);
    method = strtok(line, " ");
    path = strtok(NULL, "?");
    printf("Method = %s\n", method);
    printf("%s\n", path);
    fflush(stdout);
}