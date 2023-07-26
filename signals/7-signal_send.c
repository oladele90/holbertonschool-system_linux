#include "signals.h"

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Usage: %s <pid>\n", argv[0]);
		return (1);
	}
	if (kill(atoi(argv[1]), SIGINT) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
