#include "hls.h"

int main(int argc, char **argv)
{
	static int printer;
	int i, x, check = 2, argcount = 0, multiHls = 0;
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
						printer = 2;
					}
					else
					{
						multiHls = 1;
						printer = 0;
					}
				}
			if (argcount > 1)
				multiHls = 1;
		}
		if ((check == 0 || check == -1) && argcount > 0 && printer == 2)
			printf("\n");
		for (i = 0; i < argcount; i++)
		{
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
