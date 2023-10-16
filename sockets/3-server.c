#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

/**
* main - creates binds listens and connects to a socket
* Return: 1
*/

int main(void)
{
	int sockid = 0, sockid_c = 0, client_size = 0, server_size = 0;
	struct sockaddr_in client;
	struct sockaddr_in addrport;
	char message[1024];
	size_t len = sizeof(message), count;

	sockid = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	addrport.sin_family = AF_INET;
	addrport.sin_addr.s_addr = INADDR_ANY;
	addrport.sin_port = htons(12345);
	server_size = sizeof(addrport);
	bind(sockid, (struct sockaddr *) &addrport, server_size);
	printf("server listening on port 12345\n");
	listen(sockid, 8);
	client_size = sizeof(client);
	sockid_c = accept(sockid, (struct sockaddr *) &client, ((socklen_t *
						) &client_size));
	printf("Client connected: %s\n", inet_ntoa(client.sin_addr));
	memset(message, '\0', 1024);
	count = recv(sockid_c, message, len, 0);
	if (count)
		message[count] = '\0';
	printf("Message received: \"%s\"\n", message);
	return (1);
}
