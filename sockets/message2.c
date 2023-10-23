#include "sockets.h"

void requst_breakdown_printout(void *message)
{ 
    printf("%s\n", (char *)message);
}
/*
Raw request: "GET /test HTTP/1.1
User-Agent: curl/7.35.0
Host: localhost:8080
Accept: 

"*/