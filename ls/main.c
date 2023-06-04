#include "hls.h"

int main(int argc, char **argv)
{
	int i, x, check, argcount = 0, multiHls = 0;
	char *arglist[10], flag = '1';
	static dlist *entryInfos = NULL;


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
					check = checkArg(argv[i], argv);
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
		for (i = 0; i < argcount; i++)
		{
			if (multiHls == 1)
				printf("%s:\n", arglist[i]);
			entryInfos = hls(arglist[i], entryInfos);
			entryInfos = sortStruct(entryInfos);
			selectPrint(entryInfos, flag);
			for (x = 0; entryInfos[x].entry != NULL; x++)
			free(entryInfos[i].entry);
			free(entryInfos);
			printf("\n");
		}

	}
	return (0);
}
