#include "hreadelf.h"

char *get_type(elf_t *elf_header)
{
	static char buf[32];

	switch (EGET(e_type))
	{
		case ET_NONE:
			return ("NONE (None)");
		case ET_REL:
			return ("REL (Relocatable file)");
		case ET_EXEC:
			return ("EXEC (Executable file)");
		case ET_DYN:
			return ("DYN (Shared object file)");
		case ET_CORE:
			return ("CORE (Core file)");
		default:
			sprintf(buf, "<unknown>: %x", EGET(e_type));
	}
	return (buf);
}

int open_file(char *name, int silent, char **argv)
{
	int fd;

	fd = open(name, O_RDONLY);
	if (fd == -1 && !silent)
	{
		if (errno == EACCES)
			fflush(stdout), fprintf(stderr, ERR_NO_ACCESS, argv[0], name);
		else if (errno == ENOENT)
			fflush(stdout), fprintf(stderr, ERR_NO_ENTRY, argv[0], name);
	}
	return (fd);
}