#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

/**
* main - creates binds and listens to a socket
* Return: 1
*/

int main(void)
{
	int sockid;
	struct sockaddr_in *addrport = calloc(1, sizeof(struct sockaddr_in));

	sockid = socket(PF_INET, SOCK_STREAM, 0);
	addrport->sin_family = AF_INET;
	addrport->sin_addr.s_addr = INADDR_ANY;
	addrport->sin_port = htons(12345);
	bind(sockid, (struct sockaddr *)addrport, sizeof(struct sockaddr_in));
	printf("server listening on port 12345\n");
	while (1)
		listen(sockid, 8);
	return (1);
}
