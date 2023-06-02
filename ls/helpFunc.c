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
