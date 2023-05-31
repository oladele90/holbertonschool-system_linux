#ifndef HLS_H
#define HLS_H
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
typedef struct dirlist {
	struct dirent *entry;
	struct stat info;
	int next;
} dlist;

size_t count_ent(const char *path);
void print_ent(dlist *entryInfos);
dlist *hls(const char *path, dlist *entryInfos);
#endif
