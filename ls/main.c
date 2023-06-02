#include "hls.h"

/**
 * main - runs hls on argv
 * @argc: argument count
 * @argv: argument vector
 * Return: exit status
*/

int main(int argc, char **argv)
{
	int i;

	static dlist *entryInfos;

	if (argc == 1)
	{
		entryInfos = hls(".", entryInfos);
		entryInfos = sortStruct(entryInfos);
		print_ent(entryInfos);
	}
	if (argc > 1)
	{
		int j = 1;

		while (j < argc)
		{
			entryInfos = hls(argv[j], entryInfos);
			print_ent(entryInfos);
			j++;
		}
	}
	for (i = 0; entryInfos[i].entry != NULL; i++)
		free(entryInfos[i].entry);
	free(entryInfos);
	return (0);
}
