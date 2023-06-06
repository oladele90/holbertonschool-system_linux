#include "hls.h"

int main(int argc, char **argv)
{
	int i, x, check = 2, argcount = 0, multiHls = 0;
	char *arglist[10], flag = '1';
	static char *folders[10];
	static dlist *entryInfos = NULL;
	static int folders_count = 0;

	if (argc == 1)
	{
		entryInfos = hls(".", entryInfos);
		entryInfos = sortStruct(entryInfos);
		print_ent(entryInfos);
	}
	if (argc > 1)
	{
		for (i = 1; i < argc; i++)
		{
			if (argv[i][0] == '-')
				flag = argv[i][1];
			else
				{
					check = checkArg(argv[i], argv, folders, folders_count);
            		if (check == 1)
					{
                		arglist[argcount] = argv[i];
						argcount++;
					}
					else
						multiHls = 1;
				}
			if (argcount > 1)
				multiHls = 1;
		}
		if (check == 0 && argc > 1)
			printf("\n");
		for (i = 0; i < argcount; i++)
		{
			for (x = 0; (x < folders_count)&& (flag != 'l'); x++)
				printf("%s\n", folders[x]);
			if (multiHls == 1)
				printf("%s:\n", arglist[i]);
			entryInfos = hls(arglist[i], entryInfos);
			entryInfos = sortStruct(entryInfos);
			selectPrint(entryInfos, flag);
			for (x = 0; entryInfos[x].entry != NULL; x++)
			free(entryInfos[x].entry);
			free(entryInfos);
			printf("\n");
		}

	}
	return (0);
}
