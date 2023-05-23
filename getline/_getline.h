#ifndef _GETLINE_H_
#define _GETLINE_H_
#define READ_SIZE 5
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

char *_getline(const int fd);

#endif /* __GETLINE_H_ */