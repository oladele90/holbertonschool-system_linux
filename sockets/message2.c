#include "sockets.h"

void requst_breakdown_printout(void *message)
{
    char *line = NULL, *user_agent_ptr = NULL, *host = NULL;
    char *brk = "\r\n", *user = NULL, *accept = NULL;

    line = strtok_r(message, brk, &user_agent_ptr);
    host = strtok_r(NULL, brk, &user_agent_ptr);
    user = strtok_r(NULL, brk, &user_agent_ptr);
    accept = strtok_r(NULL, brk, &user_agent_ptr);

    printf("%s\n", line);
    printf("%s\n", user);
    printf("%s\n", host);
    printf("%s\n", accept);
}
/*
Raw request: "GET /test HTTP/1.1
User-Agent: curl/7.35.0
Host: localhost:8080
Accept: 

"*/