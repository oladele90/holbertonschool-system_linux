#include "hreadelf.h"

int main(int ac, char **argv)
{
	int ret = EXIT_SUCCESS;
	char **_argv = argv;

	if (ac < 2)
		return (fprintf(stderr, USAGE), EXIT_FAILURE);
	if (ac == 2)
		return (process_file(argv[1], 0, argv));
	while (*++_argv)
		ret += process_file(*_argv, 1, argv);
	return (ret);
}