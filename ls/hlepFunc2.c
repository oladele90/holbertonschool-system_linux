#include "hls.h"

int checkArg(char *arg, char **argv)
{
    struct stat check;

    if (lstat(arg, &check) == -1)
    {
        fprintf(stderr, "%s: cannot access %s: No such file or directory\n",argv[0] ,arg);
        return (-1);
    }
    if (S_ISREG(check.st_mode))
    {
        printf("%s\n\n", arg);
        return (0);
    }
    if (S_ISDIR(check.st_mode))
    {
        if ((check.st_mode & S_IRUSR) == 0 || (check.st_mode & S_IXUSR) == 0)
        {
            fprintf(stderr, "%s: cannot open directory %s: Permission denied\n",argv[0] ,arg);
            return (-1);
        }
        return (1);
    }
    

    return(-1);
}

void printa(dlist *entryInfos)
{
    int i = 0;

	for (i = 0; entryInfos[i].entry != NULL; i++)
			printf("%s\n", entryInfos[i].entry->d_name);
}

void printA(dlist *entryInfos)
{
    int i = 2;

	for (i = 0; entryInfos[i].entry != NULL; i++)
			printf("%s\n", entryInfos[i].entry->d_name);
}

void selectPrint(dlist *entryInfos, char flag)
{
    if (flag == '\0' || flag == '1')
        print_ent(entryInfos);

    if (flag == 'a')
        printa(entryInfos);
    
    if (flag == 'A')
        printA(entryInfos);
}