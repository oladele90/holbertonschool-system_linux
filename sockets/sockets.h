#ifndef _SOCKETS_H_
#define _SOCKETS_H_
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "unistd.h"
#include "errno.h"

void requst_breakdown_printout(void *message);
void request_res(int sockid_c);


#endif