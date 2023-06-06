#include "hls.h"

int checkArg(char *arg, char **argv, char **folders, int folders_count)
{
    struct stat check;

    if (lstat(arg, &check) == -1)
    {
        fprintf(stderr, "%s: cannot access %s: No such file or directory\n",argv[0] ,arg);
        return (-1);
    }
    if (S_ISREG(check.st_mode))
    {
        folders[folders_count] = arg;
        folders_count++;
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
        char month[4], day[3], hour[3], minute[3];
        struct passwd *owner_info = getpwuid(entryInfos[i].info.st_uid);
        struct group *group_info = getgrgid(entryInfos[i].info.st_gid);
        time_t mod_time = entryInfos[i].info.st_mtime;
        char *time_str = ctime(&mod_time);

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

            extract_time(time_str, month, day, hour, minute);
            printf("Modified time: %s %s %s:%s\n", month, day, hour, minute);

            printf(" %s\n", entryInfos[i].entry->d_name);
        }
    }
}

void extract_time(char *time_str, char* month, char* day, char* hour, char* minute) 
{
    month[0] = time_str[4];
    month[1] = time_str[5];
    month[2] = time_str[6];
    month[3] = '\0';

    day[0] = time_str[8];
    day[1] = time_str[9];
    day[2] = '\0';

    hour[0] = time_str[11];
    hour[1] = time_str[12];
    hour[2] = '\0';

    minute[0] = time_str[14];
    minute[1] = time_str[15];
    minute[2] = '\0';
}