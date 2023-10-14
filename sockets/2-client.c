#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

/**
 * main - connects to a socket
 * @argc: arg count
 * @argv: arg vector
 * Return: 0
*/

int main(int argc, char **argv)
{
	int socketfd;
	struct sockaddr_in *addrport = calloc(1, sizeof(struct sockaddr_in));
	socklen_t addr_size = sizeof(struct sockaddr_in);
	char *local = "localhost";

	if (argc != 3)
	{
		printf("Usage: %s <host> <port>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	addrport->sin_family = AF_INET;
	addrport->sin_port = htons(atoi(argv[2]));
	if (strcmp(local, argv[1]) == 0)
		inet_pton(AF_INET, "127.0.0.1", &addrport->sin_addr);
	else
		inet_pton(AF_INET, argv[1], &(addrport->sin_addr));
	if (connect(socketfd, (struct sockaddr *)addrport, addr_size) == 0)
	{
		printf("Connected to %s:%s\n", argv[1], argv[2]);
		exit(EXIT_SUCCESS);
	}
	else
	{
		printf("ERROR\n");
		exit(EXIT_FAILURE);
	}

}
