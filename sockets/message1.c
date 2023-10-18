#include "sockets.h"

void requst_breakdown_printout(void *message)
{
    char *path = NULL, *line = NULL, *method = NULL, *all_data = NULL;
    char *brk = "\r\n", *req_type = NULL;

    line = strtok(message, brk);
    method = strtok(line, " ");
    path = strtok(NULL, "?");
    all_data = strtok(NULL, " ");
    req_type = strtok(NULL, "\r\n");


    printf("Method: %s\n", method);
    printf("Path: %s\n", path);
    printf("Data: %s\n", all_data);
    printf("Request type: %s\n", req_type);
    fflush(stdout);
}