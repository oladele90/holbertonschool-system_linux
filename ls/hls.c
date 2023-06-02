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
	entryInfos = (dlist *)malloc((num_entries + 1) * sizeof(dlist));
    if (entryInfos == NULL)
	{
        perror("malloc");
        exit(EXIT_FAILURE);
	}
	for (i = 0; i < num_entries; i++) 
	{
		char fullpath[PATH_MAX];
		entry = readdir(dir);
		entryInfos[i].entry = malloc(sizeof(struct dirent));
		sprintf(entryInfos[i].entry->d_name, "%s", entry->d_name);
		sprintf(fullpath, "%s/%s", path, entry->d_name);
	   if (lstat(fullpath, &entryInfos[i].info) == -1) 
	   {
			perror("lstat");
			continue;
	   }
	}
	entryInfos[num_entries].entry = NULL;
	closedir(dir);
	return (entryInfos);
}