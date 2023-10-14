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
    struct sockaddr_in *client = NULL;
    struct sockaddr_in *addrport = calloc(1, sizeof(struct sockaddr_in));
    socklen_t *new = 0;

    sockid = socket(PF_INET, SOCK_STREAM, 0);
    addrport->sin_family = AF_INET;
    addrport->sin_addr.s_addr = INADDR_ANY;
    addrport->sin_port = htons(12345);
    bind(sockid, (struct sockaddr *)addrport, sizeof(struct sockaddr_in));
    printf("server listening on port 12345\n");
    while (1)
    {
        listen(sockid, 8);
        accept(sockid, (struct sockaddr *)client ,new);
        printf("Client connected: %s\n", inet_ntoa(client->sin_addr));
        return (1);
    }
    return (1);
}