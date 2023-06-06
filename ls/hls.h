#ifndef HLS_H
#define HLS_H
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

/**
 * struct dirlist - holds directory data
 * @entry: dirent struct
 * @info: stat struct
 * Description: holds info needed to print ls
*/

typedef struct dirlist
{
	struct dirent *entry;
	struct stat info;
} dlist;

void extract_time(char *time_str, char* month, char* day, char* hour, char* minute);
void printl(dlist *entryInfos);
void printa(dlist *entryInfoss);
void printA(dlist *entryInfos);
void selectPrint(dlist *entryInfos, char flag);
int checkArg(char *arg, char **argv);
dlist *sortStruct(dlist *entry);
int compareString(char *string1, char *string2);
void copy_d_name(const struct dirent *entry, char *dest);
size_t count_ent(const char *path);
void print_ent(dlist *entryInfos);
dlist *hls(const char *path, dlist *entryInfos);
#endif
