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