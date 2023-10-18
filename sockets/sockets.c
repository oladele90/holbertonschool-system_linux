#include "sockets.h"

void request_res(int sockid_c)
{
    char message[1024];
    char response[] = "HTTP/1.1 200 OK\r\n";
    size_t len = sizeof(message), count;

    memset(message, '\0', 1024);
    count = recv(sockid_c, message, len, 0);
	if (count)
	{
        message[count] = '\0';
		printf("Raw request: \"%s\"\n", message);
        send(sockid_c, response, strlen(response), 0);
        requst_breakdown_printout((void *)message);
        close(sockid_c);
        fflush(stdout);
    }
}

int main(void)
{
	int sockid = 0, sockid_c = 0, client_size = 0, server_size = 0;
	struct sockaddr_in client;
	struct sockaddr_in addrport;

	sockid = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	addrport.sin_family = AF_INET;
	addrport.sin_addr.s_addr = INADDR_ANY;
	addrport.sin_port = htons(8080);
	server_size = sizeof(addrport);
	bind(sockid, (struct sockaddr *) &addrport, server_size);
	printf("Server listening on port 8080\n");
    while (1)
    {
	    listen(sockid, 8);
	    client_size = sizeof(client);
	    sockid_c = accept(sockid, (struct sockaddr *) &client, ((socklen_t *
	    					) &client_size));
	    printf("Client connected: %s\n", inet_ntoa(client.sin_addr));
	    request_res(sockid_c);
    }
	return (1);
}