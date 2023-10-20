#include "sockets.h"

void requst_breakdown_printout(void *message)
{
    char *path = NULL, *line = NULL, *method = NULL, *all_data = NULL, *data = NULL;
    char *brk = "\r\n", *req_type = NULL, *save_ptr = NULL, *key = NULL, *value = NULL;

    line = strtok(message, brk);
    method = strtok(line, " ");
    path = strtok(NULL, "?");
    all_data = strtok(NULL, " ");
    req_type = strtok(NULL, "\r\n");
    printf("Path: %s\n", path);
    data = strtok_r(all_data, brk, &save_ptr);
    while(data && method && req_type)
    {
        key = strtok(data, "=");
        value = strtok(NULL, "=");
        printf("Query: \"%s\" -> \"%s\"", key, value);
        data = strtok_r(NULL, brk, &save_ptr);
    }
    return;
}