#ifndef HLS_H
#define HLS_H
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
typedef struct dirlist {
	struct dirent *entry;
	struct stat info;
} dlist;

void sortStruct(dlist *entry);
int compareString(char *string1, char *string2);
void copy_d_name(const struct dirent *entry, char *dest);
size_t count_ent(const char *path);
void print_ent(dlist *entryInfos);
dlist *hls(const char *path, dlist *entryInfos);
#endif
