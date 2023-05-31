#include "hls.h"

void print_ent(dlist *entryInfos)
{
	int i;
	for (i = 0; entryInfos[i].next != 1 ; i++)
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