#include "hls.h"

dlist *hls(const char *path, dlist *entryInfos)
{
	DIR *dir;
	struct dirent *entry;
	size_t num_entries;
	size_t i = 0;
	entryInfos = NULL;

	num_entries = count_ent(path);
	dir = opendir(path);
	if (dir == NULL) {
		perror("opendir");
		exit(EXIT_FAILURE);
	}
	entryInfos = (dlist *)malloc(num_entries * sizeof(dlist));
    if (entryInfos == NULL)
	{
        perror("malloc");
        exit(EXIT_FAILURE);
	}
	for (i = 0; i < num_entries; i++) 
	{
		entry = readdir(dir);
		char fullpath[PATH_MAX];
		entryInfos[i].entry = entry;
		sprintf(fullpath, "%s/%s", path, entry->d_name);
	   if (lstat(fullpath, &entryInfos[i].info) == -1) 
	   {
			perror("lstat");
			continue;
	   }
	}
	entryInfos[num_entries].next = 1;
	closedir(dir);
	return (entryInfos);
}