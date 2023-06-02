#include "hls.h"

void print_ent(dlist *entryInfos)
{
	int i = 0;
	for (i = 0; entryInfos[i].entry != NULL; i++)
	{
		if (entryInfos[i].entry->d_name[0] != '.')
			printf("%s\n", entryInfos[i].entry->d_name);
	}
}

size_t count_ent(const char *path)
{
	DIR *dir;
	struct dirent *entry;
	size_t num_entries = 0;

	dir = opendir(path);
	if (dir == NULL) {
		perror("opendir");
		exit(EXIT_FAILURE);
	}
	while ((entry = readdir(dir)) != NULL) 
		num_entries++;
	closedir(dir);
	return (num_entries);
}

void copy_d_name(const struct dirent *entry, char *dest) {
    size_t i;
    for (i = 0; entry->d_name[i] != '\0'; i++) {
        dest[i] = entry->d_name[i];
    }
    dest[i] = '\0';
}

/**
* sortStruct - Sorts structs by file name alphabetically
* @fileList: the array to be sorted
* Return: void
*/

dlist *sortStruct(dlist *entry)
{
	size_t i = 0;
	dlist temp;
	dlist temp2;
	int swap = 0;

	while (entry[i + 1].entry != NULL)
	{
		swap = compareString(entry[i].entry->d_name, entry[i + 1].entry->d_name);
		if (swap == 1)
		{   
			temp = entry[i];
			temp2 = entry[i + 1];
			entry[i] = temp2;
			entry[i+1] = temp;
			i = 0;
		}
		else
			i++;
	}
	return (entry);
}

/**
* compareString - compares two strings for sorting alphabetically
* @string1: string to compare
* @string2: string to compare to
* Return: 1 to swap, 0 if not -1 on error
*/
int compareString(char *string1, char *string2)
{
	int i = 0;
	char stringValue1;
	char stringValue2;

	while(string1[i] != '\0')
	{
		stringValue1 = string1[i];
		stringValue2 = string2[i];

        if (stringValue1 == '\0' && stringValue2 == '\0')
        {
            return (-1);
        }
        if (stringValue1 == '\0' && stringValue2 != '\0')
        {
            return (0);
        }
        if (stringValue1 != '\0' && stringValue2 == '\0')
        {
            return (1);
        }
		if(stringValue1 > 64 && stringValue1 < 91)
		{
			stringValue1 += 32;
		}
		if(stringValue2 > 64 && stringValue2 < 91)
		{
			stringValue2 += 32;
		}
		if (stringValue1 > stringValue2)
		{
			return (1);
		}
		if (stringValue1 < stringValue2)
		{
			return (0);
		}
		i++;
	}
    return (-1);
}
