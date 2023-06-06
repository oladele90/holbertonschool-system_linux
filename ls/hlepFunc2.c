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
        printf("%s\n", arg);
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
    int i;

	for (i = 2; entryInfos[i].entry != NULL; i++)
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

    if (flag == 'l')
        printl(entryInfos);
}

void printl(dlist *entryInfos)
{
    int i;

    for (i = 0; entryInfos[i].entry != NULL; i++)
	{
        struct passwd *owner_info = getpwuid(entryInfos[i].info.st_uid);
        struct group *group_info = getgrgid(entryInfos[i].info.st_gid);
        char time_buf[80];
        strftime(time_buf, sizeof(time_buf), "%b %e %H:%M", localtime(&entryInfos[i].info.st_mtime));
        
		if (entryInfos[i].entry->d_name[0] != '.')
        {
            printf((S_ISREG(entryInfos[i].info.st_mode)) ? "-" : "d");
            printf((entryInfos[i].info.st_mode & S_IRUSR) ? "r" : "-");
            printf((entryInfos[i].info.st_mode & S_IWUSR) ? "w" : "-");
            printf((entryInfos[i].info.st_mode & S_IXUSR) ? "x" : "-");
            printf((entryInfos[i].info.st_mode & S_IRGRP) ? "r" : "-");
            printf((entryInfos[i].info.st_mode & S_IWGRP) ? "w" : "-");
            printf((entryInfos[i].info.st_mode & S_IXGRP) ? "x" : "-");
            printf((entryInfos[i].info.st_mode & S_IROTH) ? "r" : "-");
            printf((entryInfos[i].info.st_mode & S_IWOTH) ? "w" : "-");
            printf((entryInfos[i].info.st_mode & S_IXOTH) ? "x" : "-");

            printf("%ld", entryInfos[i].info.st_nlink);

            if (owner_info != NULL)
                printf("%s ", owner_info->pw_name);

            if (group_info != NULL)
                printf("%s", group_info->gr_name);

            printf("%10ld", entryInfos[i].info.st_size);

            printf(" %s", time_buf);

            printf(" %s\n", entryInfos[i].entry->d_name);
        }
    }
}