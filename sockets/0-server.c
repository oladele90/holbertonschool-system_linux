#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "stdlib.h"
#include "stdio.h"
#include "string.h"


int main(void)
{
    int sockid;
    struct sockaddr_in *addrport = calloc(1, sizeof(struct sockaddr_in));

    sockid = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    addrport->sin_family = AF_INET;
    addrport->sin_addr.s_addr = INADDR_ANY;
    addrport->sin_port = htons(12345);
    bind(sockid, (struct sockaddr *)addrport, sizeof(addrport));
    printf("server listening on port 12345\n");
    while (1)
        listen(sockid, 8);
    return (1);
}