#include "hls.h"

int main(int argc, char **argv)
{
	static dlist *entryInfos = NULL;
	if (argc == 1)
		entryInfos = hls(".", entryInfos);
	if (argc > 1)
	{
		int j = 1;
		while (j < argc)
		{
			entryInfos = hls(argv[j], entryInfos);
			print_ent(entryInfos);
			j++;
		}
		free(entryInfos);
		return (1);
	}
	print_ent(entryInfos);
	free(entryInfos);
}