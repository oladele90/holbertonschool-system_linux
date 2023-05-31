#include "hls.h"

dlist *hls(const char *path, dlist *entryInfos)
{
	DIR *dir;
	struct dirent *entry;
	size_t num_entries = 0;
	entryInfos = NULL;

	dir = opendir(path);
	if (dir == NULL) {
		perror("opendir");
		exit(EXIT_FAILURE);
	}
	while ((entry = readdir(dir)) != NULL) 
	{
		char fullpath[PATH_MAX];
		entryInfos = (dlist *)realloc(entryInfos, (num_entries + 1) * sizeof(dlist));
		if (entryInfos == NULL)
		{
			perror("realloc");
			exit(EXIT_FAILURE);
		}
		entryInfos[num_entries].entry = entry;
		sprintf(fullpath, "%s/%s", path, entry->d_name);
	   if (lstat(fullpath, &entryInfos[num_entries].info) == -1) 
	   {
			perror("lstat");
			continue;
	   }
		num_entries++;
	}
	entryInfos[num_entries].next = 1;
	closedir(dir);
	return (entryInfos);
}