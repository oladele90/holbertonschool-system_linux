#include "sockets.h"

void requst_breakdown_printout(void *message)
{
    char *token;
    token = (char *)message;
    token = strtok(token, " ");
    printf("Method: %s\n", token);
    token = strtok(NULL, " ");
    printf("Path: %s\n", token);
    token = strtok(NULL, " \r\n");
    printf("Version: %s\n", token);
    fflush(stdout);
}